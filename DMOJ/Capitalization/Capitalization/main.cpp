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

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    string temp;
    getline(cin, temp);
    
    string fin = "";
    bool cap = true;
    for(int i = 0; i<temp.length(); i++){
        string wew = temp.substr(i, 1);
        if(wew == "."){
            cap = true;
            fin = fin + wew;
        }else if(cap == true && wew != " "){
            string asdf = wew;
            asdf[0] = toupper(asdf[0]);
            fin = fin + asdf;
            cap = false;
        }else{
            fin = fin + wew;

        }
        
    }
    cout << fin;
    
    
}