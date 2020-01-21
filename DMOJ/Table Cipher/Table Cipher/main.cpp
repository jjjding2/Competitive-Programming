#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N;
    
    int up = (int)'A' - (int)'a';
    
    string temp;
    getline(cin, temp);
    N = (int)temp.length();
    for(int i = 0; i<N; i++){

        int c = 0;
        for(int z = 0; z<temp.length(); z++){
            char asdf = temp[z];
            if(((int)asdf >= 'A' && (int)asdf <= 'Z' )|| ( (int)asdf >= 'a' && (int)asdf <= 'z')){
                if(c%2 == 1){
                    if((int)asdf > (int)'Z'){
                        asdf = (char)(asdf + up);
                    }
                }else{
                    if((int)asdf < (int)'a'){
                        asdf = (char)(asdf - up);
                    }
                }
                c ++;
                temp[z] = asdf;
            }
        }
    }
    cout << temp << "\n";

    
    
}
