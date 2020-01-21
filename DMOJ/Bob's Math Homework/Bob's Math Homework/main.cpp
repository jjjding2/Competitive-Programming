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

void test(int x){
    int ans = 0;
    for(int i = 0; i<sqrt(x*2)+1; i++){
        for(int z = 0; z + i <= x; z++){
            int sum = 0;
            for(int y = z; y<=z + i; y++){
                sum += y;
            }
            if(sum == x){
                ans ++;
                
                for(int y = z; y<=z + i; y++){
                    cout << y << " ";
                }
                cout << "\n";
                 
            }
            
        }
    }
    cout << ans << "\n";
    
}
 

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    // k(2a + k - 1)/2 = n
    
    //212
    ll n;
    cin >> n;
    //test(n);
    
    ll temp = sqrt(n*2) + 1;
    if(n/2 < sqrt(n*2)+1){
        temp = n/2;
    }
    ll ans = 1;
    for(ll i = 2; i<= temp; i++){
        
        if(n%i == 0 && i %2 == 1){
            ans ++;
            //cout << "work" << i << "\n";

        }else if(n % i == i/2 && i %2 == 0){
            ans ++;
            //cout << "work" << i << "\n";

        }
        
    }
    cout << ans << "\n";
    
}
