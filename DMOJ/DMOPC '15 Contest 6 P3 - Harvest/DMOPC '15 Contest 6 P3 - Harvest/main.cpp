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

ll pda[2001];

ll val[2001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll n, m, k;
    scanf("%lld%lld%lld", &n, &m, &k);
    for(int i = 0; i<m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        pda[l-1] ++;
        pda[r] --;
    }
    
    val[0] = pda[0];
    for(int i = 1; i<n; i++){
        val[i] = (val[i - 1] + pda[i]);
        val[i - 1] = m - val[i - 1];
    }
    val[n - 1] = m - val[n - 1];
    ll l = 0;
    ll r = -1;
    ll cursum = 0;
    ll min = INF;
    while(r <= m && l <= r+1){
        if(cursum >= k){
            if(r - l+1 < min){
                min = r - l + 1;
            }
            cursum -= val[l];
            l ++;
        }else{
            r++;
            cursum += val[r];
        }
    }
    if(min == INF){
        printf("%d", -1);
    }else{
        printf("%lld", min);
    }
    
}