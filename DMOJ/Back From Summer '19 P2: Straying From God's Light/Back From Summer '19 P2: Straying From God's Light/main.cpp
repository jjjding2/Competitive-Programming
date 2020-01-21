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

string grid[1001];

int d[3][2] = {{0,1}, {1, 0}, {-1, 0}};

queue <pii> q;

int dis[1001][1001];
int disr[1001][1001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);

    int n;
    cin >> n;
    ll ans = (n-1)*(n-1);
    for(int i = 0; i<n; i++){
        string temp;
        cin >> temp;
        grid[i] = temp;
    }
    
    q.push({0,0});
    
    memset(dis, INF, sizeof(dis));
    memset(disr, INF, sizeof(disr));

    dis[0][0] = 0; disr[0][0]=0;
    
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        for(int z = 0; z<3; z++){
            int tempx = cur.first + d[z][0];
            int tempy = cur.second + d[z][1];
            
            if(tempx >= 0 && tempx <n && tempy >= 0 && tempy <n && (grid[tempy])[tempx] == '.'){
                
                if(z ==2){
                
                    if(dis[tempx][tempy] > dis[cur.first][cur.second] + 1){
                        
                        dis[tempx][tempy] = dis[cur.first][cur.second] + 1;
                        disr[tempx][tempy] = disr[cur.first][cur.second];
                        q.push({tempx, tempy});

                    }
                }else if(z == 1){
                    if(disr[tempx][tempy] > disr[cur.first][cur.second] + 1){
                        disr[tempx][tempy] = disr[cur.first][cur.second] + 1;
                        dis[tempx][tempy] = dis[cur.first][cur.second];
                        q.push({tempx, tempy});
                    }
                }else{
                    disr[tempx][tempy] = disr[cur.first][cur.second];
                    dis[tempx][tempy] = dis[cur.first][cur.second];
                    q.push({tempx, tempy});

                }
                
            }
            
        }
        
    }
    ans += pow(dis[n-1][n-1],2);
    ans += pow(disr[n-1][n-1],2);

    if(dis[n-1][n-1] == INF){
        cout << -1;
    }else{
        cout << ans;
    }
    
    
}
