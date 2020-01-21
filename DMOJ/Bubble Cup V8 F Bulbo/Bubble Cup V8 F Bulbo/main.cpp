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

/*dp[i] = dp[j] + |x[j] - x[i]|
 dp[i] = min(dp[j] - xj) + xi
 for(xj < xi)
 
 dp[i] = min(dp[j] + xj) - xi
 for(xi > xj)
 
 */

int n, lo, hi, x; long long ans;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &n, &x); lo = hi = x;
    for(int i = 0, L, R; i<n; i++){
        scanf("%d%d", &L, &R);
        
        if(L > hi){
            ans += L - hi;
            lo = hi; hi = L;
        }else if(R < lo){
            ans += lo - R;
            hi = lo; lo = R;
        }else{
            lo = max(lo, L); hi = min(hi, R);
        }
        
        
    }
    printf("%lld\n", ans);
    
}