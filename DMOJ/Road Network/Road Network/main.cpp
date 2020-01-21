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
typedef unordered_map<string, bool> umii;

umii temp;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
struct edge{int a; int b; double w;};

pii coord[1001];
edge arr[1000001];
int p[1001];
bool vis[1001][1001];
double ans = 0;


bool cmp(edge a, edge b){
    return a.w < b.w;
}
int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}



int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i<=n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        coord[i] = {x, y};
        p[i] = i;
    }
    
    int count = 0;
    for(int i = 0; i<m; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        arr[count].a = x;
        arr[count].b = y;
        arr[count].w = 0;
        count ++;
        vis[x][y] = true;
        vis[y][x] = true;
    }
    
    for(int i = 1; i<=n; i++){
        for(int z = i+1; z <= n; z++){
            if(!vis[i][z]){
            arr[count].a = i;
            arr[count].b = z;
            arr[count].w = sqrt(pow(coord[i].first-coord[z].first, 2) + pow(coord[i].second-coord[z].second, 2));
            count ++;
                vis[i][z] = true;
                vis[z][i] = true;
            }
        }
    }
    
    sort(arr, arr + count, cmp);
    
    int ee = 0;
    
    for(int i = 0; i<count; i++){
        int u = arr[i].a;
        int v = arr[i].b;
        if(ee == n- 1){
            break;
        }
        int fu = Find(u); int fv = Find(v);
        if(fu != fv) {
            p[fu] = fv;
            ee ++;
            ans += arr[i].w;

        }
    }
    printf("%.2f", ans);
    
}
