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

string temp, a, b;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int t;
    cin >> t;
    for(ll z = 1; z<=t; z++){
        
        cin >> temp;
    
        a = "";
        b = "";
        bool lead = true;
        for(int i = 0; i<temp.length(); i++){
            
            if(temp[i] == '0'){
                a = a + "0";
                if(lead == false){
                    b = b + "0";
                }
            }else if(temp[i] == '1'){
                a = a + "1";
                
                if(lead == false){
                    b = b + "0";
                }
                
            }else if(temp[i] == '2'){
                a = a + "1";
                b = b + "1";
                lead = false;
            }else if(temp[i] == '3'){
                a = a + "2";
                b = b + "1";
                lead = false;
            }else if(temp[i] == '4'){
                a = a + "2";
                b = b + "2";
                lead = false;

            }else if(temp[i] == '5'){
                a = a + "3";
                b = b + "2";
                lead = false;

            }else if(temp[i] == '6'){
                a = a + "3";
                b = b + "3";
                lead = false;

            }else if(temp[i] == '7'){
                a = a + "5";
                b = b + "2";
                lead = false;

            }else if(temp[i] == '8'){
                a = a + "5";
                b = b + "3";
                lead = false;

            }else if(temp[i] == '9'){
                a = a + "6";
                b = b + "3";
                lead = false;

            }

            
        }
        if(b == ""){
            b = "0";
        }
        
        cout << "Case #" << z << ": " << a << " " << b << "\n";
        

    }
    
}