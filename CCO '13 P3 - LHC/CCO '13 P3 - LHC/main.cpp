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

int N, dis[4001], dia; long long cnt[4001], num; vector<int> adj[4001];

void dfs(int u, int pa){
    dis[u] = 0; cnt[u] = 1;
    for(int v: adj[u]){
        if(v == pa) continue;
        dfs(v, u);
        if(dis[u] + dis[v] + 1 > dia){
            dia = dis[u] + dis[v] + 1; num = cnt[u]*cnt[v];
        }else if(dis[u] + dis[v] + 1 == dia){
            num += cnt[u]*cnt[v];
        }
        if(dis[v] + 1 > dis[u]){
            dis[u] = dis[v] + 1; cnt[u] = cnt[v];
        }else if(dis[v] + 1 == dis[u]){
            cnt[u] += cnt[v];
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d", &N);
    for(int i = 1, x, y; i < N; i++){
        scanf("%d%d", &x, &y);
        adj[x].push_back(y); adj[y].push_back(x);
    }
    dfs(1, 0); printf("%d %lld\n", dia+1, num);
    
}
