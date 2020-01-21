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

vector <pii> adj[1001];

queue <int> q;

int edge;

int dis[1001];

bool bad[1001][1001];

pii bfss(int cur){
    memset(dis, INF, sizeof(dis));
    
    q.push(cur);
    int maxv = 0;
    int maxi = cur;
    dis[cur] = 0;
    while(!q.empty()){
        int temp = q.front();q.pop();
        for(pii j: adj[temp]){
            
            if(!bad[temp][j.first]){
                
                if(dis[j.first] > dis[temp]+1){
                    dis[j.first] = dis[temp] + 1;
                    if(dis[j.first] > maxv){
                        maxv = dis[j.first];
                        maxi = j.first;
                    }
                    q.push(j.first);
                    
                }
            }
            
        }
        
    }
    return {maxv, maxi};
}

int dia(int cur){
    pii temp = bfss(cur);
    return bfss( temp.second ).first;
}

bool vis[1001];

int nodes(int cur){
    memset(vis, false, sizeof(vis));
    q.push(cur);
    int ans = 1;
    vis[cur] = true;
    while(!q.empty()){
        int temp = q.front();q.pop();
        for(pii j: adj[temp]){
            
            if(!bad[temp][j.first]){
                
                if(!vis[j.first]){
                    vis[j.first] = true;
                    q.push(j.first);
                    ans ++;
                }
                
            }
            
        }
    }
    return ans;
    
    
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);

    int n, q;
    cin >> n >> q;
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    
    for(int i = 0; i<q; i++){
        int a, b;
        cin >> a >> b;
        bad[a][b] = true;
        bad[b][a] = true;
        if(nodes(a) < nodes(b)){
            cout << dia(a) +1<< "\n";
        }else{
            cout << dia(b) +1<< "\n";
        }
        bad[a][b] = false;
        bad[b][a] = false;
        
    }
    
}
