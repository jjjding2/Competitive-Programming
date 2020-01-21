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

int dp[3001][3001];

int a1[3001];
int b1[3001];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int a, b;
    cin >> a >> b;
    
    for(int i = 0; i<a; i++){
        
        cin >> a1[i];
    }
    for(int i = 0; i<b; i++){
        cin >> b1[i];
        
    }
    
    for(int i = 1; i<=a; i++){
        
        for(int z = 1; z<=b; z++){
            if(a1[i-1] != b1[z-1]){
                dp[i][z] = max(dp[i - 1][z], dp[i][z-1]);
            }else if(a1[i-1] == b1[z-1]){
                dp[i][z] = dp[i-1][z-1] + 1;
            }
            
        }
        
    }
    cout << dp[a][b];
    
    
    
    
}