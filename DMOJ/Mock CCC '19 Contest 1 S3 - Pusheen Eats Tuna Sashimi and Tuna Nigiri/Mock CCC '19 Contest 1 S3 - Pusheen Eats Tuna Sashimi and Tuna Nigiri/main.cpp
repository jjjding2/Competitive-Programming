#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct e{ll x; ll y; ll vx; ll vy;};

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int x, y, ex, ey;

ll dis[105][2][204][2][2][2];

void dfs(e temp){
    for(int i = 0; i<4; i++){
        ll newx = temp.vx + temp.x + d[i][0];
        ll newvx = temp.vx + d[i][0];
        ll newy =temp.vy + temp.y + d[i][1];
        ll newvy = temp.vy + d[i][1];
        
        if(newx >= 0 && newx <= x && newy >= 0 && newy <= y){
            int indx1 = 0;
            int indy1 = 0;
            int indx2 = 0;
            int indy2 = 0;
            
            ll vx1 = abs(temp.vx);
            ll vy1 = abs(temp.vy);
            ll vx2 = abs(newvx);
            ll vy2 = abs(newvy);
            
            if(temp.vx < 0){
                indx1 = 1;
                vx1 = vx1 + 102;
            }
            if(temp.vy < 0){
                indy1 = 1;
                vy1 = vy1 + 102;
            }
            if(newvx < 0){
                indx2 = 1;
                vx2 = vx2 + 102;
            }
            if(newvy < 0){
                indy2 = 1;
                vy2 = vy2 + 102;
            }
            if(dis[temp.x][temp.y][vx1][vy1][indx1][indy1] + 1 < dis[newx][newy][vx2][vy2][indx2][indy2]){
                dis[newx][newy][vx2][vy2][indx2][indy2] = dis[temp.x][temp.y][vx1][vy1][indx1][indy1] + 1;
                dfs({newx, newy, newvx, newvy});

            }
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    
    int t;
    scanf("%d%d%d", &x, &y, &t);
    
    
    int sx, sy;
    scanf("%d%d", &sx, &sy);
    
    scanf("%d%d", &ex, &ey);
    memset(dis, INF, sizeof(dis));
    dis[sx][sy][0][0][0][0] = 0;
    dfs({sx, sy, 0, 0});
    
    if(dis[ex][ey][0][0][0][0] == INF){
        printf("%d\n", -1);
    }else{
        printf("%lld\n", dis[ex][ey][0][0][0][0]);
    }
    
    for(int i = 0; i<=x; i++){
        for(int z = 0; z<=y; z++){
            cout << dis[i][z][0][0][0][0] << " ";
        }
    }
    
}