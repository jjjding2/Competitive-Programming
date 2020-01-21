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
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

vector <plu> adj[10000];

ll dis[10000];
const ll LOG = 15;

ll lca[LOG+10][10000];

ll n;

ll dep[10000];

// LCA Template
// Lowest Common Ancestor

void dfs(ll cur, ll pre){
    for(pii j: adj[cur]){
        if(j.first != pre){
            dis[j.first] = dis[cur] + j.second;
            dep[j.first] = dep[cur] + 1;
            lca[0][j.first] = cur;
            dfs(j.first, cur);
        }
    }
    
}

void build_lca(){
    for(ll i = 1; i<=LOG; i++){
        for(ll z = 0; z<n; z++){
            if(lca[i-1][z]!=-1){
                lca[i][z] = lca[i-1][lca[i-1][z]];
            }
        }
    }
}

ll get_lca(ll a, ll b){
    if(dep[a] < dep[b]) swap(a, b);
    for(ll i = LOG-1; i>=0; i--){
        if(lca[i][a] != -1 && dep[lca[i][a]] >= dep[b]){a = lca[i][a];}
    }
    if(a == b) return a;
    for(ll i = LOG-1; i>=0; i--){
        if(lca[i][a]!=-1 && lca[i][b]!=-1 && lca[i][a] != lca[i][b]){ a = lca[i][a]; b = lca[i][b];}
    }
    return lca[0][a];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    cin >> n;
    
    for(ll i = 0; i<n-1; i++){
        ll a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    memset(lca, -1, sizeof(lca));
    dfs(0, -1);
    build_lca();

    ll q;
    cin >> q;
    for(ll i = 0; i<q; i++){
        ll a, b;
        cin >> a >> b;
        ll rt = get_lca(a, b);
        cout << dis[a] + dis[b] - 2*dis[rt] << "\n";
    }
    
    
}
