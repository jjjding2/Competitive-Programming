#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


vector <int> adj[100001];

vector <int> adj2[100001];

vector <int> adj3[100001];


bool gym[100001];

int dis[100001];

int dis2[100001];

int L, node, edge;

int L2, edge2;


void prune(int u, int par){
    if(dis[u]>L && gym[u]){ L = dis[u]; node = u; }
    for(int v: adj[u]){
        if(v != par){
            dis[v] = dis[u]+1;  prune(v, u);
            if(gym[v] || !adj2[v].empty()) { adj2[u].push_back(v); adj2[v].push_back(u); edge++; }
        }
    }
}

void prune2(int u, int par){
    if(dis2[u]>L2 && gym[u]){ L = dis2[u]; node = u; }
    for(int v: adj[u]){
        if(v != par){
            dis2[v] = dis[u]+1;  prune2(v, u);
            if(gym[v] || !adj3[v].empty()) { adj3[u].push_back(v); adj3[v].push_back(u); edge2++; }
        }
    }
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, K, F;
    scanf("%d%d%d", &N, &K, &F);
    gym[F] = true;
    for(int i = 0; i<K; i++){
        int a;
        scanf("%d", &a);
        gym[a] = true;
    }
    
    for(int i = 0; i<N-1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        
        
    }
    prune(1, -1);
    
    gym[F] = false;
    prune2(1, -1);
    
    
    cout << edge2*2 - L2;
    
    
}