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

pii cherry[10001];

vector <pii> adj[10001];


int n, cost, k, ans;

pii dp[10001];

void dfs(int p, int c){
    
    if(p != c){
        for(pii j: adj[c]){
            dfs(c, j.first);
            cherry[c].first += cherry[j.first].first;
            cherry[c].second += cherry[j.first].second;
        }
        if(cherry[c].first >= cost && cherry[c].second <= k&& c != 1){
            ans ++;
        }
    }
    
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d%d", &n, &cost, &k);
    for(int i = 1; i<=n; i++){
        scanf("%d", &cherry[i].first);
    }
    for(int i = 0; i<n-1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        cherry[b].second += c;
        adj[a].push_back({b, c});
    }
    
    dfs(-1, 1);
    

    printf("%d", ans);
    
}