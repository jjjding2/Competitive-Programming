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
 
 dp state, min for f(a, b), to convert y-axis to x-axis
 
 base case
 dp[0][j] = I * j (start from 0 to get to the character)
 dp[i][0] = D * i (delete everything to get nothing)
 
 transition
 
 if same, dp[i - 1][j - 1
 else
 dp[i - 1][j] + D  (delete
 dp[i][j - 1] + I
 dp[i - 1][j - 1] + R
 
 i -> exe
 
 */

int dp[1001][1001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int D, I, R;
    cin >> D >> I >> R;
    string a, b;
    cin >> a >> b;

    for(int i = 0; i<=b.length(); i++){
        dp[0][i] = I*i;
    }
    for(int i = 0; i<=a.length(); i ++){
        dp[i][0] = D * i;
    }
    for(int i = 1; i<=a.length(); i++){
        for(int z = 1; z<=b.length(); z++){
            
            if(a[i-1] == b[z-1]){
                dp[i][z] = dp[i - 1][z-1];
            }else{
                dp[i][z] = min(min(dp[i - 1][z] + D, dp[i][z - 1] + I), dp[i - 1][z - 1] + R);
            }
            
        }
    }
    cout << dp[a.length()][b.length()];
    
    
}