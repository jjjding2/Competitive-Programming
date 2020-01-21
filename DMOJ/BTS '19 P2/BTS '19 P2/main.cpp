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

ll origx;
ll origy;

ll solvey(ll x, ll ylo, ll yhi){
    ll a = x/2;
    ll b = x%2;
    
    ll y = a + b * 2;
    
    while(a >= 0){
        
        
        y = a + b*2;
        if((ylo < y && y < yhi) || (x == origx && y == origy)){
            return a + b;
        }
        a--;
        b += 2;
    }
    if(ylo <= y && y < yhi){
        return a + b;
    }else{
        return 10e9;
    }
    
}

ll solvex(ll y, ll xlo, ll xhi){
    ll a = y/2;
    ll b = y%2;
    
    ll x = a + b * 2;
    
    while(a >= 0){
        
        
        

        
        x = a + b*2;
        if((xlo < x && x < xhi) || (x == origx && y == origy)){
            return a + b;
        }
        a--;
        b += 2;
    }
    if(xlo <= x && x < xhi){
        return a + b;
    }else{
        return 10e9;
    }
    
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    
    ll x, y, h, v;

    cin >> x >> y >> h >> v;
    origx = x;
    origy = y;
    ll t;
    cin >> t;
    t = t-1;
    if(solvey(x, y, y + v) <= t){
        cout << "YES";
    }else if(solvey(x + h, y, y + v) <= t){
        cout << "YES";
    }else if(solvex(y, x, x + h-1) <= t){
        cout << "YES";
    }else if(solvex(y + v, x, x + h-1) <= t){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
}
