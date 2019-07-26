#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

ll dp[251][251];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    
    for(int i= 1; i<=n; i++){
        dp[1][i] = 1;
    }
    for(int i = 1; i<=max(n, k); i++){
        dp[i][i] = 1;
    }
    
    for(int z = 2; z<=k; z++){
        for(int i = z; i<=n; i++){
            dp[z][i] = dp[z-1][i - 1] + dp[z][i - z];
        }
    }
    cout << dp[k][n];
}