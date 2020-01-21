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

/*
 dp[l][r][0]
    dp[l + 1][r][0] + (x[l + 1] - x[l])*(n - lr - l))
    dp[l + 1][r][1] + (x[r] - x[l])*(n - (r - l))
 
 dp[l][r][1]
    dp[l][r-1][0] + (x[r] - x[l])*(n - (r - l))
    dp[l][r - 1][l] + (x[r] - x[r-1])*(n - (r - l))
 
 dp[1][n][0]
 dp[1][n][1]
 
 */

ll n, L;

ll arr[2001];

ll dp[2001][2001][2];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%lld%lld", &n, &L);
    int spot = 1;
    arr[n+1] = L;
    for(int i = 1; i<=n; i++){
        scanf("%lld", &arr[i]);
        if(arr[i] < L){
            spot ++;
        }
    }
    n += 1;
    sort(arr, arr + n + 1);
    for(int i = 1; i<=n; i++){
        if(arr[i] == L){
            spot = i;
        }
    }
    memset(dp, INF, sizeof(dp));
    
    dp[spot][spot][0] = dp[spot][spot][1] = 0;
    
    for(ll len = 1; len<n; len ++){
        for(ll l = 1; l + len <=n; l ++){
            ll r = l + len;
            dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + (n - (r - l))*(arr[l + 1] - arr[l]));
            dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + (n - (r - l))*(arr[r] - arr[l]));

            dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][1] + (n - (r - l))*(arr[r] - arr[r - 1]));
            dp[l][r][1] = min(dp[l][r][1], dp[l][r-1][0] + (n - (r - l))*(arr[r] - arr[l]));
        }
    }
    printf("%lld\n", min(dp[1][n][0], dp[1][n][1]));
    
    
    
}
