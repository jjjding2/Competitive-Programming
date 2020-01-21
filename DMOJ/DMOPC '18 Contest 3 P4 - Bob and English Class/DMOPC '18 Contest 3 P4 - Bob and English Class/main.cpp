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

int K, N, cnt[2000002], sz[2000002]; vector<pii> adj[2000002]; ll ans = 0;
void dfs1(int u, int pa){
    sz[u] = cnt[u];
    for(auto e: adj[u]){
        if(e.first != pa){dfs1(e.first, u); sz[u] += sz[e.first];}
        
    }
    
}
int getCentroid(int u, int pa, int tot){
    for(auto e: adj[u]){
        if(e.first != pa && sz[e.first]*2 > tot) return getCentroid(e.first, u, tot);
    }
    return u;
    
}
void dfs2(int u, int pa, int dis){
    ans += 1LL*cnt[u]*dis;
    for(auto e: adj[u]){
        if(e.first != pa) dfs2(e.first, u, dis + e.second);
        
    }
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &K, &N);
    
    for(int i = 1, x; i<=K; i++){
        scanf("%d", &x); cnt[x]++;
    }
    for(int i = 1, u, v, w; i < N; i++){
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w}); adj[v].push_back({u, w});
        
    }
    dfs1(1, -1); int rt = getCentroid(1, -1, K); dfs2(rt, -1, 0);
    printf("%lld\n", ans);
    
}
