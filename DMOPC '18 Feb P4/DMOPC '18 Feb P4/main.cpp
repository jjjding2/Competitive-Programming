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
typedef map<string,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

umii val;

int n;
string a, b;

bool check(string cur){
    
    string ship = cur;
    
    if(cur == b){
        return true;
    }
    for(int i = 0; i<n-1; i++){
        ship = cur;
        if(ship[i] == ship[i + 1]){
            if(ship[i] == 'A'){
                ship[i] = 'F';
                ship[i + 1] = 'F';
            }else{
                ship[i] = 'A';
                ship[i + 1] = 'A';
            }
            if(val.count(ship) == 0){
                val.emplace(ship, 1);
                if(check(ship) == true){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n;
    cin >> a >> b;
    if(check(a) == true){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
    
}