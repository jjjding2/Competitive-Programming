#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int num[10000];

ll fact(ll n)
{
    int v = 1;
    for (int i = 2; i <= n; i++)
        v = v * i;
    return v;
}

ll comb(ll n, ll r)
{
    return fact(n)/(fact(r)*fact(n - r));
}



int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll n, k;
    scanf("%lld%lld", &n, &k);
    ll choose;
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        if(num[a] == 0){
            choose ++;
        }
        num[a] ++;
    }
    ll temp = comb(k, choose);
    
    ll individual = temp * choose;
    individual = individual/k;
    
    ll tot = 0;
    
    for(int i = 0; i<1001; i++){
        if(num[i]!= 0 && num[i] != 1){
            tot += individual*num[i]%998244353 ;
        }
    }
    printf("%lld", temp%998244353);
    
}