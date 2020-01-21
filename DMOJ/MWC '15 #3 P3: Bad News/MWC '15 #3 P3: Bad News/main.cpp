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

char grid[30][30];

int d[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0},{1,1},{-1,-1},{-1,1},{1,-1}};
int n, q;

bool check(string word, bool vis[26][26], pii coord){
    vis[coord.first][coord.second] = true;
    if(word.length() == 0){
        return true;
    }
    for(int i = 0; i<8; i++){
        
        int tempx = coord.first + d[i][0];
        int tempy = coord.second + d[i][1];
        if(tempx >= 0 && tempx < n && tempy >= 0 && tempy < n && !vis[tempx][tempy] && grid[tempx][tempy] == word[0]){
            
            if(check(word.substr(1, word.length()), vis, {tempx, tempy})){
                return true;
            }

        }
        
    }
    
    return false;
}
bool vis1[26][26];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n >> q;
    
    for(int i = 0; i<n; i++){
        for(int z = 0; z<n; z++){
            
            cin >> grid[i][z];
            grid[i][z] = tolower(grid[i][z]);
        }
        
    }
    
    for(int i = 0; i<q; i++){
        string temp;
        cin >> temp;
        bool good = false;
        
        for(int x = 0; x<n; x++){
            if(good == true){
                break;
            }
            for(int y = 0; y<n; y++){
                
                if(grid[x][y] == temp[0]){
                    if(good == false && check(temp.substr(1, temp.length()), vis1, {x, y})){
                        cout << "good puzzle!" <<"\n";
                        good = true;
                        break;
                    }else{
                        continue;
                    }
                    
                }
                memset(vis1, false, sizeof(vis1));

            }
        }
        
        if(!good){
            cout << "bad puzzle!" << "\n";
        }
        
    }
    
}
