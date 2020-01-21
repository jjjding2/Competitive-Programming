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
typedef pair<ll, ll> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

umii smap;

vector <pii> adj[100001];

queue <int> qtemp;
vector <int> stores;
bool store[100001];

PQ q;

ll dis[100001];

ll dis2[101][101];

ll n, m, k;
bool v[13];

void dijkstra(ll start){
    q.push({0, start});
    memset(dis, INF, sizeof(dis));
    
    dis[start] = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(dis[temp.second] < temp.first){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                q.push({dis[j.first], j.first});
                
                if(store[j.first] && j.first != start){
                    dis2[smap.at(start)][smap.at(j.first)] = min(dis2[smap.at(start)][smap.at(j.first)], dis[j.first]);
                }
                
            }
        }
        
    }
    
}


ll ans = INF;
void solve(bool vis[13], ll val, ll pre, ll count){
    
    if(count == k){
        ans = min(ans, val + dis2[0][pre]);
    }else{
    
        for(int j = 1; j<=k; j++){
            if(!vis[j]){
                vis[j] = true;
                solve(vis, val + dis2[pre][j], j, count + 1);
                vis[j] = false;
            }
        }
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n >> m;
    for(int i = 0; i<m ;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    cin >> k;
    smap.emplace(0, 0);
    for(int i = 1; i<=k; i++){
        int a;
        cin >> a;
        stores.push_back(a);
        smap.emplace(a, i);
        store[a]=true;
    }
    memset(dis2, INF, sizeof(dis2));
    dijkstra(0);
    for(int j: stores){
        dijkstra(j);
    }
    
    
    solve(v, 0, 0, 0);
    cout << ans << "\n";
    
    /*
    for(int i = 0; i<=k; i++){
        cout << i << "\n";
        for(int z = 0; z<=k; z++){
            cout << dis2[i][z] << " ";
        }
        cout << "\n";
        
    }
     */
    
    
    
    
    
}
