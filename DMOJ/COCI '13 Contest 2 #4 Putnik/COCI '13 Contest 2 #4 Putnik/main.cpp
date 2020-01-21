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

//starting from lowest, you either add the new point to the front or the end of the sequence

//dp state is minimum from L to R

int dp[1501][1501];
int adj[1501][1501];
int n;
int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            scanf("%d", &adj[i][j]);
        }
    }
    memset(dp, 0xf3, sizeof(dp));
    dp[1][1] = 0;
    for(int i = 1; i<n; i++){
        for(int j = 1; j<n; j++){
            int cur = max(i, j) + 1;
            dp[i][cur] = min(dp[i][cur], dp[i][j] + adj[j][cur]);
            dp[cur][j] = min(dp[cur][j], dp[i][j] + adj[cur][i]);
        }
    }
    int ans = 2e9;
    for(int i = 1; i<n; i++)
        ans = min(ans, min(dp[i][n], dp[n][i]));
    printf("%d\n", ans);
    
}
