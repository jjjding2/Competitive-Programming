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
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}
int dp[70000][600];
int arr[70000];
int arr1[70000];
int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int t;
    cin >> t;
    while(t--){
        int n, k, w;
        cin >> n >> k >> w;
        for(int i = 0; i<n; i++){
            cin >> arr[i];

        }
        for(int i = 0; i<n + w + 1; i++){
            if(i!=0){
                arr[i] += arr[i-1];
            }
        }
        for(int i = 0; i<n+w+1; i++){
            if(i == 0){
                arr1[i] = arr[i+w-1];

            }else{
                arr1[i] = arr[i+w-1] - arr[i-1];
            }
            
        }
        int ans = 0;
        for(int i = 1; i<=k; i++){
            for(int z = n-1; z>=0; z--){
                dp[z][i] = max(dp[z+1][i], dp[z+w][i-1] + arr1[z]);
                ans = max(dp[z][i],ans);
            }
        }
        cout << ans << "\n";
        memset(dp, 0, sizeof(dp));
        memset(arr, 0, sizeof(arr));
        memset(arr1,0,sizeof(arr1));
    }
    
}
