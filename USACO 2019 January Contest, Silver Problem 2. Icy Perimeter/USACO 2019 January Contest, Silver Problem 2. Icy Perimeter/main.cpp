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

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char arr[1001][1001];

queue <pii> q1;

queue <pii> q;

queue <pii> Q;

int p[1001][1001];

bool vis[1001][1001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("perimeter.in","r",stdin); freopen("perimeter.out","w",stdout);
    
    int n;
    cin >> n;
    string ree;
    getline(cin,ree);
    for(int i = 1; i<=n; i++){
        string temp;
        getline(cin, temp);
        for(int z = 1; z<=n; z++){
            arr[i][z] = temp[z-1];
            if(temp[z-1] == '#'){
                q.push({i, z});
                q1.push({i, z});
            }
        }
    }
    while(!q1.empty()){
        int curx = q1.front().first; int cury = q1.front().second; q1.pop();
        p[curx][cury] = 4;
        for(int i = 0; i<4; i++){
            int newx = curx + d[i][0];
            int newy = cury + d[i][1];
            if(arr[newx][newy] == '#'){
                p[curx][cury] --;
            }
        }
        
    }
    
    int maxv = 0;
    int maxp = 0;
    

    while(!q.empty()){
        int cursum = 0;
        int curp = 0;
        int curx = q.front().first; int cury = q.front().second; q.pop();
        if(!vis[curx][cury]){
            cursum ++;
            curp += p[curx][cury];
            vis[curx][cury] = true;
            Q.push({curx, cury});
            while(!Q.empty()){
                curx = Q.front().first; cury = Q.front().second; Q.pop();
                for(int i = 0; i<4; i++){
                    int newx = curx + d[i][0];
                    int newy = cury + d[i][1];
                    if(arr[newx][newy] == '#' && !vis[newx][newy]){
                        vis[newx][newy] = true;
                        cursum ++;
                        curp += p[newx][newy];
                        Q.push({newx, newy});
                    }
                }
            }
            if(cursum > maxv || (maxv == cursum && curp < maxp)){
                maxv = cursum;
                maxp = curp;
            }
        }
    }
    printf("%d %d\n", maxv, maxp);
}