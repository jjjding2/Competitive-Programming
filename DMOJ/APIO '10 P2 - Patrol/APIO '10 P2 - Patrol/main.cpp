#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

const int MM = 100005;
int N, K, dia, rt, pre[MM], dis[MM], d1[MM], d2[MM]; unordered_map<int, int> adj[MM];
void dfs1(int u, int pa, int dis){
    pre[u] = pa;
    if(dis > dia) {dia = dis; rt = u;}
    for(pair<int, int> p: adj[u]){
        if(p.first != pa) dfs1(p.first, u, dis + 1);
    }
    
}

void dfs2(int u, int pa){
    d1[u] = 0;
    d2[u] = 0;
    for(auto p: adj[u]){
        if(p.first == pa) continue;
        int v=p.first, w = p.second;
        dfs2(v, u);
        if(d1[v] +w > d1[u]){d2[u] = d1[u]; d1[u] = d1[v] + w;;}
        else if(d1[v] + w > d2[u]){d2[u] = d1[v] + w;}
        
    }
    if(d1[u] + d2[u] > dia) dia = d1[u] + d2[u];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &N, &K);
    for(int i = 1, u, v; i < N; i++){
        scanf("%d%d", &u, &v); adj[u][v] = 1; adj[v][u] = 1;
        
    }
    dfs1(1, -1, 0); dia = 0; dfs1(rt, -1, 0);
    
    int ans = 2*(N-1) - dia + 1;
    
    if(K == 1){ printf("%d\n", ans); return 0;}
    for(int i = rt; pre[i] > 0; i = pre[i]){
        adj[i][pre[i]] = -1;
        adj[pre[i]][i] = -1;
    }
    dia = 0;
    dfs2(1, -1);
    printf("%d", ans - dia+1);
    
}
