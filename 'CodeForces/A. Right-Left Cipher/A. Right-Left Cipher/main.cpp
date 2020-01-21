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
    cin.tie(0); cin.sync_with_stdio(0);
    string temp;
    cin >> temp;
    
    string final = "";
    
    if(temp.length() == 1){
        cout << temp;
    }else if(temp.length()%2 == 0){
        for(int i = 0; i<=100; i++){
            if(i%2 == 1){
                string asdf = temp.substr((i+1)/2 + temp.length()/2-1, 1);
                final = final + asdf;
            }else{
                string asdf = temp.substr(temp.length()/2-1 - i/2, 1);
                final = final + asdf;
            }
            if(final.length() == temp.length()){
                break;
            }
        }
        cout << final;
    }else if(temp.length()%2 == 1){
        for(int i = 0; i<=100; i++){
            if(i%2 == 1){
                string asdf = temp.substr((i+1)/2 + temp.length()/2, 1);
                final = final + asdf;
            }else{
                string asdf = temp.substr(temp.length()/2 - i/2, 1);
                final = final + asdf;
            }
            if(final.length() == temp.length()){
                break;
            }
        }
        cout << final;
    }
    
}