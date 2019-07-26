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

set<string> s;

string simplify(string temp){
    string temp2 = "";
    bool at = false;
    bool plus = false;
    for(int i = 0;i<temp.length();i++){
        if(temp[i]>='A' && temp[i] <= 'Z' && plus == false){
            temp2 += temp[i]+(abs('a'-'A'));
        }else if(temp[i] == '@'){
            temp2 += temp[i];
            at = true;
            plus = false;
        }else if(temp[i] == '.' && at == false){
            
        }else if(temp[i] == '+' && at == false){
            plus = true;
            
        }
        else if(plus == false){
            temp2 += temp[i];
        }
    }
    return temp2;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA11.txt","r",stdin);
    
    for(int z = 0; z<10; z++){
        int n;
        cin >> n;
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            string temp;
            cin >> temp;
            
            string val = simplify(temp);
            if(!s.count(val)){
                ans ++;
                s.insert(val);
            }
        }
        cout << ans << "\n";
        s.clear();
    }
    
}
