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

ll arr[2100];


ll dp[2100];

ll dp2[2100];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, t, q;
    cin >> n >> t >> q;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }
    dp[0] = 1;
    for(int z = 1; z<=n; z++){
        
            for(ll x = t; x>=arr[z]; x--){
                if(dp[x - arr[z]] > 0){
                    dp[x] = (dp[x - arr[z]]%MOD + dp[x]%MOD)%MOD;
                }
            }
            
        
    }
    
    for(int i =0; i<q; i++){
        int a, b, d;
        cin >> a >> b >> d;

            
        ll ans = 0;
        for(int x = 0; x<=d; x++){
            dp2[x] = dp[x];
        }
        for(ll x = arr[a]; x <= d; x++){
            if(dp2[x - arr[a]] > 0){
                dp2[x] = (dp2[x]%MOD - dp2[x - arr[a]]%MOD + MOD)%MOD;
            }
        }
        for(ll x = arr[b]; x <= d; x++){
            if(dp2[x - arr[b]] > 0){
                dp2[x] = (dp2[x]%MOD - dp2[x - arr[b]]%MOD + MOD)%MOD;
            }
        }
        
        
        for(int z = 0; z<=d - arr[a] - arr[b]; z++){
            ans = (dp2[z]%MOD + ans%MOD + MOD)%MOD;

        }
        cout << ans%MOD << "\n";
        

    }
    
}
