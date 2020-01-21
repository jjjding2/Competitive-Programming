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

int arr[10001][3];

int val[9];

int ans = 0;
int n, k;


bool check(int l, int r){
    int maxv = 0;
    int maxv2 = 0;
    for(int i = l; i<= r; i++){
        if(arr[i][0] > maxv){
            maxv = arr[i][0];
        }
        if(arr[i][1] > maxv2){
            maxv2 = arr[i][1];
        }
    }
    if(abs(maxv2 - maxv) <= k){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int t;
    cin >> t;
    for(int z = 0; z<t; z++){
        
        cin >> n >> k;
        
        for(int i = 0; i<n; i++){
            scanf("%d", &arr[i][0]);
            
        }
        for(int i = 0; i<n; i++){
            scanf("%d", &arr[i][1]);
        }
        for(int l = 0; l < n; l++){
            for(int r = l; r < n; r++){
                if(check(l, r)){
                    ans ++;
                }
            }
            
        }
        cout << "Case #" << z + 1 << ": " << ans << "\n";
        ans = 0;
        memset(arr, 0, sizeof(arr));
        
    }
    
    
}
