#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<pair<int, int>, int> piii;
typedef pair<int, int> pii;

typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct edge{int b; int c; int s;};

vector <edge> adj[1605];

queue <pii> q;

int dis[1605][3601];
bool done[1610][3610];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int S;
    int n, e;
    scanf("%d%d%d", &S, &n, &e);
    
    for(int i = 0; i<e; i++){
        
        int a, b, s;
        int c;
        scanf("%d%d%d%d", &a, &b, &c, &s);
        adj[a].push_back({b, c, s*c});
        adj[b].push_back({a, c, s*c});
        
    }
    
    q.push({0,0});

    memset(dis, INF, sizeof(dis));
    dis[0][0] = 0;
    int val = INF;
    done[0][0] = true;

    while(!q.empty()){
        pii num = q.front(); q.pop();

        done[num.first][num.second] = false;

        for(edge j: adj[num.first]){
            if(j.s + num.second <= S && dis[j.b][j.s + num.second] > dis[num.first][num.second] + j.c){
                dis[j.b][j.s + num.second] = dis[num.first][num.second] + j.c;

                if(!done[j.b][j.s + num.second]){

                    done[j.b][j.s + num.second] = true;
                    q.push({j.b, j.s + num.second});
                }
            }
        }
    }

    for(int i = 0; i<=S; i++){
        val = min(val, dis[n-1][i]);
    }
    if(val == INF){
        printf("-1");
    }else{
    printf("%d", val);
    }
    
    
}