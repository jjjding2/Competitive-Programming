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

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll a, b, c, d, e, N;

ll f(ll x){
    if(x == 0){
        return e;
    }else{
        return(a*f((ll)x/b%MOD)%MOD + c*f((ll)x/d%MOD)%MOD)%MOD;
    }
}

int main(){
    scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &N);
    printf("%lld", f(N)%MOD);
}