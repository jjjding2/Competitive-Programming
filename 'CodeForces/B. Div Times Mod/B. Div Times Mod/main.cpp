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

ll n, k;

ll minv = INF;

void check(ll a, ll b){
    for(ll i = b%k; i<= a*k + k; i+= k){
        if(i%k == b){
            if(i / k == a){
                if(i < minv){
                    minv = i;
                }
            }
    
        }
    }
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    
    
    scanf("%lld%lld", &n, &k);
    for(int i = 1; i<=sqrt(n); i++){
        if(n % i == 0){
            check(n/i, i);
            check(i, n/i);
        }
    }
    
    printf("%lld\n", minv);
    
}