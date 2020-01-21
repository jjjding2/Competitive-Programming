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
int n, w;

int arr[1000003][21];

void compute(){
    
    for(int j = 1; j<= 20; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            arr[i][j] = max(arr[i][j-1], arr[i + (1 <<( j-1))][j-1]);
        }
        
    }
    
    
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n >> w;
    
    for(int i = 0; i<n; i++){
        cin >> arr[i][0];
    }
    compute();
    for(int i = 0; i + w - 1 < n; i++){
        int j = log2(w);
        cout << max(arr[i][j], arr[i + w - 1 - (1 << j)+1][j]) << " ";
        
    }
    
}
