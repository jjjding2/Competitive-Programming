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

int in[100003];
bool vis[100003];
vector<int> adj[100003];

queue <pii> q;

int n, d;
int ans = 0;

void fill(){
    for(int i =1; i<=n; i++){
        if(in[i] == 0 && !vis[i]){
            q.push({i, 0});
            ans ++;
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("DATA41.txt","r",stdin);
    
    for(int t = 0; t<10; t++){
        scanf("%d%d", &n, &d);
        for(int i = 0; i<n-1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            in[b] ++;
        }
        
        fill();
        while(!q.empty()){
            pii temp = q.front(); q.pop();
            if(temp.second == d){
                for(int j: adj[temp.first]){
                   
                    in[j]--;
                    if(in[j] == 0 ){
                        vis[j] = true;
                        q.push({j, 0});
                        ans ++;
                    }
                    
                }
            }else{
                for(int j: adj[temp.first]){
                    if(!vis[j] ){
                        vis[j] = true;
                        q.push({j, temp.second + 1});
                    }
                }
            }
            
        }
        printf("%d\n", ans);
        
        memset(in, 0, sizeof(in));
        memset(vis, false, sizeof(vis));
        memset(adj, 0, sizeof(adj));
        ans = 0;
        
    }
    
}
