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

vector <pii> adj[50000];

int dis[501][501];

priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 1; i<=n; i++){
        q.push({0, i});
        
        while(!q.empty()){
            pii temp = q.top(); q.pop();
            if(dis[i][temp.second] < temp.first){
                continue;
            }
            for(pii j: adj[temp.second]){
                if((dis[i][j.first] == 0 && j.first != i) || dis[i][j.first] > dis[i][temp.second] + j.second){
                    dis[i][j.first] = dis[i][temp.second] + j.second;
                    q.push({dis[i][j.first], j.first});
                }
            }
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i<q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", dis[a][b]);
    }
    
}