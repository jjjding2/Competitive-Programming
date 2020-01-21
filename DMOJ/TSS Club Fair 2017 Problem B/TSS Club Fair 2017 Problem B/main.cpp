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

ll house[186800];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i<=n; i++){
        ll x, y;
        scanf("%lld%lld", &x, &y);
        house[i] = (x*x + y*y);
    }
    sort(house, house + n+1);
    for(int i = 0; i<q; i++){
        ll r;
        scanf("%lld",&r);
        r = r * r;
        int lo = 0;
        int hi = n;
        int mi = (lo + hi)/2;
        while(lo <= hi){
            if(house[mi] <= r){
                lo = mi + 1;
            }else{
                hi = mi - 1;
            }
            mi = (lo + hi)/2;
        }
        printf("%d\n", mi);
        
    }
}
