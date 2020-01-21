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

int arr[300001];


ll bit [30][300001];

void update(int a, int b, int spot){
    
    for(int i = a; i<=300001; i+= i&(-i)){
        bit[spot][i] += b;
    }
    
}

ll query(ll x, ll spot){
    ll ans = 0;
    for(; x > 0; x-=(x&-x)){
        
        ans += bit[spot][x];
        
    }
    return ans;
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        update(i, 1, arr[i]);
    }
    
    
    for(int i = 0; i<m; i++){
        int q;
        cin >> q;
        if(q == 1){
            int a, b;
            cin >> a >> b;
            
            update(a, -1, arr[a]);
            
            arr[a] = b;
            update(a, 1, b);
        }else{
            ll l, r, c;
            cin >> l >> r >> c;
            int curi = 21;
            while(c > 0){
                curi --;
                c = c - query(r, curi) + query(l-1, curi);
            }
            cout << curi << "\n";
        }
    }
    
    
    
    
}
