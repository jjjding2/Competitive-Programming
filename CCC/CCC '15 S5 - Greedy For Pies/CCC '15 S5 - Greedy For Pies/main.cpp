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

//sort the M pies, the left side is if you occupy a position, and the right side is using the value

/*dp[i][l][r][can use]: max value
 i is the current position
 left is the left pointer
 r is the right pointer
 can is if you can use the previous value
 
 A is the current pies, B is the backup pies
 
 if(i < n){
    ans = dp[i + 1][l][r][1]
 
    if(can) ans = max(ans, A[i] + dp[i + 1][l][r][0]);
 }
 if(l <= r){ (B array not finished)
    ans = dp[i][l + 1][r][1]
    if(can) ans = dp[i][l][r - 1][0] + B[r];
 }
 
 
 */

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    
    
}