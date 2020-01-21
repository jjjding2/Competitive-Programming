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

vector <pii> adj[MAXN];

bool vis[MAXN];

int con[MAXN];

int mult[MAXN];


int minma[MAXN][2];
int n, m, k;

void dfs(int cur, int pre, bool neg){
    if(neg == true){
        mult[cur] = 1;
    }else{
        mult[cur] = -1;
    }
    
    for(pii j: adj[cur]){
        if(!vis[j.first] && j.first != pre){
            vis[j.first] = true;
            con[j.first] = j.second - con[cur];
            dfs(j.first, cur, !neg);
        }
    }
}

void dfs2(int cur, int pre){
    for(pii j: adj[cur]){
        if(!vis[j.first] && j.first != pre){
            vis[j.first] = true;
            if(mult[j.first] == 1){
                minma[j.first][1] = min(minma[cur][1], max(k - con[j.first], 0));
                
                minma[j.first][0] = max(minma[cur][0], con[j.first]*-1 + 1);
            }else{
                minma[j.first][0] = max(minma[cur][0], max(con[j.first] - k, 0));
                
                minma[j.first][1] = min(minma[cur][1], con[j.first]);
            }
            dfs2(j.first, cur);
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i<m; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 1; i<=n; i++){
        minma[i][0] = 1;
        minma[i][1] = k;
    }
    
    dfs(1, -1, true);
    
    memset(vis, false, sizeof(vis));
    dfs2(1, -1);
    int up = INF;
    int down = 1;
    for(int i = 1; i<=n; i++){
        up = min(minma[i][1], up);
        down = max(minma[i][0], down);
    }
    cout << up - down << "\n";
    
}
