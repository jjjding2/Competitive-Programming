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


int val = 0;


int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N;
    scanf("%d", &N);
    
    string temp;
    cin >> temp;
    
    int sum = 0;
    
    
    for(int i = 0; i<N; i++){
        for(int z = i; z<N; z++){
            string asdf = temp.substr(i, z - i + 1);
            bool good = true;
            
            for(int x = 0; x<asdf.length(); x++){
                if(asdf[x] != temp[x]){
                    good = false;
                    break;
                }
            }
            for(int x = (int)asdf.length()-1; x>-1; x--){
                if(asdf[x] != temp[x + (N - asdf.length())]){
                    good = false;
                    break;
                }

            }
            if(good){
                sum ++;

            }
            
        }
    }
    printf("%d", sum);
    
}