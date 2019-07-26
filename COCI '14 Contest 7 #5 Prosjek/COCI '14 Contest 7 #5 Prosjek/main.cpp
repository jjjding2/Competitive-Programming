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

//
//ai + ai + 2 + an >= length * average
//(ai - average) + (a[i + 1] - average) ... >= 0
//use psa to find the average

int N, K, a[300002];
ll ans;
ll psa[300002];

bool check(int x){
    ll mi = 1e18 + 1;
    for(int i = 1; i<=N; i++){
        psa[i] = psa[i - 1] + a[i] - x;
        if(i >= K) mi = min(mi, psa[i - K]);
        if(psa[i] >= mi) return true;
        //psa[r] - min(psa[l], l < r - k)
    }
    return false;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &N, &K);
    for(int i = 1; i<=N;i++){
        scanf("%d", &a[i]); a[i]*=1000;
    }
    int lo = 1, hi = 1e9 + 1;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid; lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    printf("%.4f\n", ans/1000.0);
    
}