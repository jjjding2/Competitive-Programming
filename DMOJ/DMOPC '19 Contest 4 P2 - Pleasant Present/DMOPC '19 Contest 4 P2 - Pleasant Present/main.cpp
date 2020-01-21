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
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

struct edge{
    int ax; int ay; int bx; int by;
};

int dis[16][16][16][16];

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

queue <edge> q;



int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, startx, starty, endx, endy;
    cin >> n >> startx >> starty >> endx >> endy;
    int cx, cy;
    cin >> cx >> cy;
    int dx, dy;
    cin >> dx >> dy;
    
    if(dx == startx && dy == starty){
        swap(cx, dx);
        swap(cy, dy);
    }
     
    
    q.push({cx, cy, dx, dy});
    memset(dis, INF, sizeof(dis));
    dis[cx][cy][dx][dy] = 0;
    
    //a is for ball
    //b is for empty

    while(!q.empty()){
        edge c = q.front(); q.pop();
        int curdis = dis[c.ax][c.ay][c.bx][c.by];
        for(int i = 0; i<4; i++){

            int newx =c.bx + d[i][0];
            int newy =c.by + d[i][1];
            if(newx >= 1 && newx <= n && newy >= 1 && newy <=n){
                if((newx != c.ax || newy != c.ay) && dis[c.ax][c.ay][newx][newy] > curdis + 1){
                    q.push({c.ax, c.ay,newx,newy });
                    dis[c.ax][c.ay][newx][newy] = curdis + 1;
                }
            }

        }
        if(((abs(c.ax - c.bx) == 1 && abs(c.ay - c.by) == 0) || (abs(c.ax - c.bx) == 0 && abs(c.ay - c.by) == 1)) && dis[c.bx][c.by][c.ax][c.ay] > curdis + 1){
            dis[c.bx][c.by][c.ax][c.ay] = curdis + 1;
            q.push({c.bx, c.by, c.ax, c.ay});
        }
        
        
    }
    int minv = INF;
    for(int i = 1; i<=n; i++){
        
        for(int z = 1; z<=n; z++){
            
            if(dis[endx][endy][i][z] < minv){
                minv = dis[endx][endy][i][z];
            }
            
        }
        
    }
    

    cout << minv;
    
    
}
