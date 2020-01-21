#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector <int> adj[100001];

queue <int> q;

int dis[100001][4];


void bfs(int start, int num){
    
    q.push(start);
    dis[start][num] = 0;
    while(!q.empty()){
        int temp = q.front(); q.pop();
        
        for(int j: adj[temp]){
            if(dis[j][num] > dis[temp][num] + 1){
                q.push(j);
                dis[j][num] = dis[temp][num] + 1;
            }
        }
    }
    
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N, M;
    scanf("%d%d", &N, &M);
    
    int s, a, b;
    scanf("%d%d%d", &s, &a, &b);
    for(int i = 0; i<M; i++){
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    memset(dis, INF, sizeof(dis));
    bfs(s, 1);
    bfs(a, 2);
    bfs(b, 3);
    
    int v1 = dis[a][1];
    int v2 = dis[b][1];
    int same = 0;
    for(int i = 1; i<=N; i++){
        if(dis[i][1] > same && dis[i][1] + dis[i][2] == v1 && dis[i][1] + dis[i][3] == v2){
            same = dis[i][1];
        }
    }
    printf("%d", same);
    
    
    
}