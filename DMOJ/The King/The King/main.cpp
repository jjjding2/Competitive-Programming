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

ll dp[11][101][1 << 10], ans;
int tot, mask[1 << 10], cnt[1 << 10];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    //Check every row
    //dp[row i][k kings][ mask j]
    
    //dp[i][k][mask j] += dp[i - 1][k - # of ones(mask[j])][mask p]
    
    //To check if two masks on different rows are compatible or not
    //mask[j]&( mask[p] | mask[p] << 1 | mask[p] >> 1)
    int n, k;
    scanf("%d%d", &n, &k);
    
    
    
    for(int i = 0; i<(1 << n); i++){
        if(!i &(i>> 1)){
            mask[++tot] = 1;
        }
        cnt[i] = _builtin_popcount(i);
    }
    
    
}