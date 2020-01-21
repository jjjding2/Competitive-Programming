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

int arr[402];

int dp[401][401];

int s(int a, int b){
    return arr[b] - arr[a];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
        dp[i][i] = true;
    }
    int sum = 0;
    for(int z = 0; z<=n/2; z++){
        
        for(int i = 1; i + 2*z <= n; i ++){
            if( dp[i][i + z] && dp[i+z][i + 2*z] && s(i, i + z) == s(i + z, i + 2*z)){
                dp[i][i + 2*z] = true;
                sum = max(s(i, i + 2*z), sum);

            }
            if(i + 2*z + 1 <= n){
                if( dp[i][i + z] && dp[i + z + 1][i + 2*z + 1] && s(i, i + z) == s(i+z+1,i+2*z+1 ) ){
                    dp[i][i + 2*z + 1] = true;
                    sum = max(s(i, i + 2*z + 1), sum);
                }
            }
            
        }
        
    }
    cout << sum;
    
    
}
