#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    string type;
    cin >> type;
    
    double a1, b1, c1;
    double a2, b2, c2;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    if(type=="Multiply"){
        cout << a1*a2 << " " << b1*b2 << " " << c1*c2 << "\n";
    }else if(type == "Screen"){
        cout << 1 - (1 - a1)*(1 - a2) << " " << 1 - (1 - b1)*(1 - b2) << " " << 1 - (1 - c1)*(1 - c2) << "\n";

    }else{
        if(a1 < 0.5){
            cout << 2 * a1 * a2;
        }else{
            cout << 1 - 2*(1 - a1)*(1 - a2);
        }
        cout << " ";
        if(b1 < 0.5){
            cout << 2 * b1 * b2;
        }else{
            cout << 1 - 2*(1 - b1)*(1 - b2);
        }
        cout << " ";
        if(c1 < 0.5){
            cout << 2 * c1 * c2;
        }else{
            cout << 1 - 2*(1 - c1)*(1 - c2);
        }
    }
    
    
}