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
int n;

ll tot = 0;

ll ans = 0;

void solve(int arr[], int i, int tot){
    int prev = 1;
    if(i != 0){
        prev = arr[i -1 ];
    }
    
    if(tot == 0 && i != 1){
        cout << n << "=";
        ans ++;
        for(int z = 0; z<i; z++){
            cout <<arr[z];
            if(z != i - 1){
                cout << "+";
            }
        }
        cout << "\n";
    
    }else{
        for(int z = 1; z<=tot; z++){
            if(z >= prev){
                arr[i] = z;
                solve(arr, i + 1, tot - z);
            }
            
        }
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int arr[51];
    cin >> n;
    if(n == 1){
        cout << "total=0";
    }else{
        solve(arr, 0, n);
        cout << "total=" << ans;
    }
    
}