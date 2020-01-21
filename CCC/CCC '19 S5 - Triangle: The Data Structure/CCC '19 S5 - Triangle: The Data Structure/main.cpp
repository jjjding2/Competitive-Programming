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

ll arr[3001][3001];

ll bit[3001][3001];

ll query(int x, int y, ll val){
    ll sum = 0;
    for(;y > 0; y -= y&-x ){
        sum = max(bit[x][y], sum);
    }
    return sum;
}
void update(int x, int y, ll val){
    
    for(int i = 0; i<x; i++){
        
        for(;y <=10e9; y+= y&-y){
            bit[i][y] = max(val, bit[i][y]);
        }
        
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);

    for(int i = 1; i<=n; i++){
        
        for(int z = 1; z<= i; z++){
            scanf("%lld", &arr[i][z]);
        }
        
    }
    
    
    
    /*
    ll ans = 0;

        for(int a = 1; a < k; a++){
            for(int i = 1; i<=n-a; i++){
                
                for(int z = 1; z<= i; z++){
                    arr[i][z] = max(arr[i][z], max(arr[i+1][z + 1], arr[i+1][z]));

                }
            }
        }
        for(int i = 1; i<=n-k+1; i++){
            
            for(int z = 1; z<= i; z++){
                ans += arr[i][z];
            }
        }
    
        
        printf("%lld", ans);
    
    */
    
}
//5 3
//3 1 2 4 3 5 6 2 4 3 3 5 2 7 1
