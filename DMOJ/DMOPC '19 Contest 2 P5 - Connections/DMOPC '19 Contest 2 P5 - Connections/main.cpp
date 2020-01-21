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

int d[101];

vector <int> adj[101];

queue <int> q;

int dis[101];
int n;

int bfs(int a, int b){
    memset(dis, INF, sizeof(dis));
    dis[a] = 0;
    dis[b] = 0;
    q.push(b);
    q.push(a);
    while(!q.empty()){
        
        int temp = q.front(); q.pop();
        
            for(int j: adj[temp]){
                if(dis[j] > dis[temp] + 1){
                    dis[j] = dis[temp] + 1;
                    q.push(j);
                }
            }
        
        
    }
    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans += dis[i]*d[i];
    }
    return ans;
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> d[i];
    }
    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int minv = INF;
    for(int i = 1; i <= n; i++){
        
        for(int z = 1; z<=n; z++){
            
            minv = min(minv, bfs(i, z));
            
        }
        
    }
    cout << minv;
    
    
}
