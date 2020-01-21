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
struct e{int x; int y; int vx; int vy;};


int dis[101][101];

int dis2[101][101];




queue <e> q;


int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int x1, y1, t;
    scanf("%d%d%d", &x1, &y1, &t);
    
    
    int sx, sy;
    scanf("%d%d", &sx, &sy);
    
    int ex, ey;
    scanf("%d%d", &ex, &ey);
    
    
    
    
    q.push({sx, sy, 0, 0});
    
    memset(dis, INF, sizeof(dis));
    dis[sx][sy] =0;
    while(!q.empty()){
        e temp = q.front(); q.pop();
        for(int i = 0; i<4; i++){
            
            int newx = temp.vx + temp.x + d[i][0];
            int newvx = temp.vx + d[i][0];
            int newy =temp.vy + temp.y + d[i][1];
            int newvy = temp.vy + d[i][1];
            
            if(newx >= 0 && newx <= x1 && newy >= 0 && newy <= y1){
                
                if(dis[newx][newy] > dis[temp.x][temp.y]){
                    
                    dis[newx][newy] = dis[temp.x][temp.y]+ 1;
                    q.push({newx, newy, newvx, newvy});
                    
                }
                
            }
        }
        
        
    }
    
    q.push({ex, ey, 0, 0});
    
    memset(dis2, INF, sizeof(dis2));
    dis2[ex][ey] =0;
    while(!q.empty()){
        e temp = q.front(); q.pop();
        for(int i = 0; i<4; i++){
            
            int newx = temp.vx + temp.x + d[i][0];
            int newvx = temp.vx + d[i][0];
            int newy =temp.vy + temp.y + d[i][1];
            int newvy = temp.vy + d[i][1];
            
            if(newx >= 0 && newx <= x1 && newy >= 0 && newy <= y1){
                
                if(dis2[newx][newy] > dis2[temp.x][temp.y]){
                    
                    dis2[newx][newy] = dis2[temp.x][temp.y]+ 1;
                    q.push({newx, newy, newvx, newvy});
                    
                }
                
            }
        }
        
        
    }
    
    int minv = INF;
    
    for(int i = 0; i<x1; i++){
        for(int z = 0; z<x1; z++){
            if(dis[i][z] + dis2[i][z] < minv && i != sx && i != ex && z != sy && z != ey){
                minv = dis[i][z] + dis2[i][z];
            }
        }
    }
    
    if(minv== INF){
        printf("%d\n", -1);
    }else{
        printf("%d\n", minv);
    }
    
    
    
}