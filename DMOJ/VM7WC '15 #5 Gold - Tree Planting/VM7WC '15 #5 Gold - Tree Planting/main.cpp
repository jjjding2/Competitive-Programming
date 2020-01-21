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

ll bit [2001][2001];

void update(int a, int b, int spot){
    
    for(int i = a; i<=2001; i+= i&(-i)){
        bit[spot][i] += b;
    }
    
}

ll query(int x, int spot){
    ll ans = 0;
    for(; x > 0; x-=(x&-x)){
        
        ans += bit[spot][x];
        
    }
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        if(a == 1){
            int r, c, d;
            cin >> r >> c >> d;
            
            int diagonal = r + c -1;
            int location = diagonal - c + 1;
            
            update(location, d, diagonal);
            
        }else{
            int r, c, x;
            cin >> r >> c >> x;
            
            int diagonal = r + c - 1;
            int location = diagonal - c + 1;
            
 
            ans += query(location, diagonal) - query(location -x-1, diagonal);
        }
        
    }
    cout << ans%MOD << "\n";
    
}
