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

ll p[1000009];



ll hsh1[1000009];
ll hsh2[1000009];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    string a, b;
    cin >> a >> b;
    
    ll a1 = (ll)a.length();
    ll b1 = (ll)b.length();
    
    hsh1[0] = a[a1 - 0 - 1] - 'A' + 1;
    hsh2[0] = b[0] - 'A' + 1;
    p[0] = 1;
    
    for(int i = 1; i<=min(a1, b1); i ++){
        p[i] =(p[i - 1]*131);
        hsh1[i] = (hsh1[i-1]*131 + (a[a1 - i - 1] - 'A' + 1));
        hsh2[i] = (hsh2[i - 1] + ( p[i]*(b[i] - 'A' + 1) ));
    }

    
    

    ll ans = a1;
    for(int mi = min(a1,b1); mi >= 0 ; mi --){
        
        if(hsh1[mi] == hsh2[mi] ){
            ans = mi;
            break;
        }

    }
    cout << a.substr(0, a1 - ans -1) << b << "\n";
    
}
