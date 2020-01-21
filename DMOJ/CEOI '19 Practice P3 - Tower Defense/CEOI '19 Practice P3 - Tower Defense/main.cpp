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

int a1, a2, b1, b2;

int d;

int dis;
void vert(int x){
    
    int ydis = abs(a2 - b2) + 1;
    
    int xpos = a1 + x*-1;
    
    int walls = d - dis -2 + ydis;
    
    int ypos = min(a2, b2) - (walls - ydis)/2;
    
    cout << walls << "\n";
    
    for(int i = 0; i<walls; i++){
        cout << xpos << " " << ypos + i << "\n";
    }
    
}
void hor(int x){
    
    int hdis = abs(a1 - b1) + 1;
    
    int ypos = a2 + x*-1;
    
    int walls = d - dis -2 + hdis;
    
    int xpos = min(a1, b1) - (walls - hdis)/2;
    
    cout << walls << "\n";
    
    for(int i = 0; i<walls; i++){
        cout << xpos + i << " " << ypos << "\n";
    }
    
    
}

void corner(int x, int y){
    cout << (d - 4) << "\n";

        for(int i = 1; i<=(d - 4)/2; i++){
            cout << a1 + -1*x*i << " " << a2 << "\n";
        }
    
    
    for(int i = 1; i<=(d - 4)/2; i++){
        cout << a1 << " " << a2 + i*-1*y << "\n";
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    

    cin >> a1 >> a2 >> b1 >> b2 >> d;
    
     dis = abs(a1 - b1) + abs(a2 - b2);
    
    if(d < dis || (d - dis)%2 == 1 || (dis == 1 && d > 1)){
        cout << "impossible" << "\n";
    }else if(d == dis){
        cout << 0 << "\n";
    }else{
        if(abs(a1 - b1) == 1 && abs(a2 - b2) == 1){
            if(d < 6){
                cout << "impossible" << "\n";
            }else{
                corner(a1 - b1, a2 - b2);
            }
            
        }
        else if(a1 == b1 || a2 == b2){
            
            if(a1 == b1){
                if(b2 > a2){
                    hor(-1);
                }else{
                    hor(1);
                }
                
            }else if(a2 == b2){
                if(b1 > a1){
                    vert(-1);
                }else{
                    vert(1);
                }
            }
            
            
        }else if(abs(a1 - b1) < 2 || abs(a2 - b2) < 2){
            
            if(abs(a2 - b2) < 2){
                if(b1 > a1){
                    vert(-1);
                }else{
                    vert(1);
                }
            }else if(abs(a1 - b1) < 2){
                if(b2 > a2){
                    hor(-1);
                }else{
                    hor(1);
                }
            }
            
        }else{
            if(b1 > a1){
                vert(-1);
            }else{
                vert(1);
            }
        }
        
        
        
    }
    
}
