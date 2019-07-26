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

/*
dp state, number of ways to make j confusion for i numbers
 
 transition state
 
 dp[i][j] = dp[i-1][j-i+1] + dp[i - 1][j -i+ 2] + dp[i - 1][j - i+3] + dp[i - 1][j]...
 
 
 */

int dp[1002][10002];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, C;
    scanf("%d%d", &N, &C);
    
    dp[0][0] = 1;
    for(int i = 1; i<=N; i++){
        dp[i][0] = 1;
        for(int j = 1; j<=C; j++){
            if(j >= i){
                dp[i][j] = (dp[i - 1][j] - dp[i - 1][j - i] + MOD)%MOD;
                
                //1 2 3 4, must insert 5
                //(1, 2, 3), 5, 4
                //(1, 2), 5, 3, 4
                //(1), 5, 2, 3, 4
                
            }else{
                dp[i][j] = dp[i - 1][j]%MOD;
            }
            dp[i][j] = (dp[i][j] + dp[i][j - 1])%MOD;
        }
    }
    cout << dp[N][C]%MOD;
    
    
    
}