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

ll c1[3];
ll v1[3];

ll dp[3][100010];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll N, W;
    cin >> N >> W;

    int f = 0; //alternate between two arrays
    int s = 1;

    for(int i = 0; i<N; i++){
        f = i%2;
        s = (i + 1)%2;
        
        for(int z = 0; z<3; z++){
            cin >> c1[z] >> v1[z];
        }
        
        for(ll z= W; z >=0; z--){
            if(z - c1[0] >= 0 ){
                dp[f][z] = max(max(dp[0][z], dp[s][z - c1[0]] + v1[0]), dp[1][z]);
            }
            if(z - c1[1] >= 0){
                
                dp[f][z] = max(max(dp[0][z], dp[s][z - c1[1]] + v1[1]), dp[1][z]);
            }
            if(z - c1[2] >= 0){
                
                dp[f][z] = max(max(dp[0][z], dp[s][z - c1[2]] + v1[2]), dp[1][z]);
            }
            dp[f][z] = max(dp[0][z], dp[1][z]);
            
        }
            
        
        
        
    }
    cout << dp[f][W];
}