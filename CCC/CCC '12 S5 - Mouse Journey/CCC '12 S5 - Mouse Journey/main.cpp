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

bool catv[30][30];

queue <pii> q;

bool vis[30][30];

int d[2][2] = {{0, 1}, {1, 0}};

ll dp[30][30];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int r, c;
    scanf("%d%d", &r, &c);
    
    int cat;
    scanf("%d", &cat);
    
    for(int i = 0; i<cat; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        catv[x][y] = true;
    }
    
    q.push({1, 1});
    dp[1][1] = 1;
    while(!q.empty()){
        pii cur = q.front();
        q.pop();
        for(int z = 0; z<2; z++){
            
            int tempx = cur.first + d[0][z];
            int tempy = cur.second +d[1][z];
            if(!catv[tempx][tempy] && tempx >= 1 && tempx <= r && tempy >= 1 && tempy <= c){
                dp[tempx][tempy] += dp[cur.first][cur.second];
                if(!vis[tempx][tempy]){
                q.push({tempx, tempy});
                vis[tempx][tempy] = true;
                }
            }
            
        }
    }
    printf("%lld", dp[r][c]);
    
    
    
}
