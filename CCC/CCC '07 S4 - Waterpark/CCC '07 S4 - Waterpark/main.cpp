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

vector <int> adj[10000];

int dp[10000];

bool vis[10000];

void dfs(int cur){
    vis[cur] = true;

    for(int j: adj[cur]){
        if(!vis[j]){
            dfs(j);
        }
        dp[cur] += dp[j];

        
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    
    int a, b;
    scanf("%d%d", &a, &b);
    adj[b].push_back(a);
    while(a != 0 && b != 0){
        scanf("%d%d", &a, &b);
        adj[b].push_back(a);
    }
    dp[1] = 1;
    dfs(n);
    cout << dp[n];
}