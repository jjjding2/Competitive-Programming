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

priority_queue<int, vector<int>, greater<int>>q;

char arr[1001][1001];

pii cur = {1, 0};
bool jumping = false;

int j, w, h;


bool jump(){
    while(cur.first <= j && jumping){
        
        cur.first ++;
        
        if(arr[cur.first][cur.second + 1] == '.' && arr[cur.first][cur.second + 2] == '.'){
            cur.second += 2;
            
            
            bool good = true;
            
            bool weird = false;
            
            
            for(int i = cur.first; i > 0; i--){
                if(arr[i][cur.second] == '@'){
                    good = false;
                    weird = true;
                }
            }
            
            if(good){
                cur.first = 1;
                jumping = false;
            }else if(!good && weird){
                cout << cur.second<< "\n";
                return false;
            }else{
                cout << cur.second +2<< "\n";
                return false;
            }
            
        }else if(arr[cur.first + 1][cur.second] == '@'){
            cout << cur.second +2<< "\n";
            return false;
        }else if(arr[cur.first][cur.second + 1] == '.' && arr[cur.first][cur.second + 2] == '@' && cur.first == j + 1){
            cur.second += 1;
            cout << cur.second + 1 << "\n";
            return false;
        }
        
        if(cur.first == j+1){
            cout << cur.second +2<< "\n";
            return false;
        }
            
    }
    return true;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //setprecision(5)
    freopen("DATA32.txt","r",stdin);
    
    for(int y = 0; y < 10; y++){
        
        cin >> j >> w >> h;
        for(int i = h-1; i>=0; i--){
            string temp;
            cin >> temp;
            for(int z = 0; z<w; z++){

                arr[i][z] = temp[z];
                if(arr[i][z] == 'L'){
                    cur = {i, z};
                }
            }
            
        }
        
        bool success = true;
        while(arr[cur.first][cur.second+1] != 'G' && arr[cur.first][cur.second] != 'G'){
            if(!jumping && arr[cur.first][cur.second+1] == '.'){
                cur.second ++;
            }else if(arr[cur.first][cur.second+1] == '@'){
                jumping = true;
                if(jump() == false){
                    success = false;
                }
                
            }
            if(success == false){
                break;
            }
            
        }
        if(success){
            cout << "CLEAR" << "\n";
        }
        
        cur = {1, 0};
        jumping = false;
        
    }
    
    
}