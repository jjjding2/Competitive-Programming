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

int f[100005];
int e[100005];

int dp[100005];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    for(int i = 3; i<n+3; i++){
        scanf("%d", &f[i]);
        
    }
    for(int i = 3; i<n+3; i++){
        scanf("%d", &e[i]);
    }
    
    for(int i = 3; i<n+3; i++){
        dp[i] = max(max(f[i] + dp[i - 2] + e[i - 1], e[i] + dp[i - 1]), f[i] + dp[i - 3] + e[i - 2] + f[i - 1]);
    }
    cout << dp[n + 2];
}