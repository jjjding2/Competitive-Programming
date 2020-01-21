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


struct edge{int a; int b; int c; int d; int spot;};

bool cmp(edge a, edge b){
    if(a.c == b.c){
        return a.spot < b.spot;
    }
    return a.c < b.c;
}

int p[100001];

int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}

edge e[200001];

int dis[100001];

vector <pii> adj[100001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 1; i<=m; i++){
        int a, b, c, d;
        scanf("%d%d%d", &a, &b, &c);
        d = 1;
        if(i < n){
            d = 0;
        }
        e[i-1] = {a, b, c, d, i};
    }
    sort(e, e + m, cmp);
    int cnt = 0;
    for(int i = 1; i<=n; i++){
        p[i] = i;
    }
    int ee = 0;
    int maxv = 0;
    for(int i = 0; i<m; i++){
        int u = e[i].a;
        int v = e[i].b;
        if(ee == n- 1){
            break;
        }
        int fu = Find(u); int fv = Find(v);
        if(fu != fv) {
            maxv = e[i].c;
            if(dis[fu] < dis[fv]){
                p[fu] = fv;
            }else if(dis[fv] < dis[fu]){
                p[fv] = fu;
            }else{
                p[fv] = fu;
                dis[fu] ++;
            }
            if(e[i].d == 1){
                cnt ++;
            }
            ee ++;
        }
    }
    
    if(m > n - 1){
        for(int i =  0; i<=n; i++){
            p[i] = i;
        }
        for(int i = 0; i<m; i++){
            int fu = Find(e[i].a); int fv = Find(e[i].b);
            if(fu != fv){
                if(e[i].c < maxv || (e[i].c == maxv && !e[i].d)){
                    if(dis[fu] < dis[fv]){
                        p[fu] = fv;
                    }else if(dis[fv] < dis[fu]){
                        p[fv] = fu;
                    }else{
                        p[fv] = fu;
                        dis[fu] ++;
                    }
                }else if(!e[i].d && e[i].c <= d){
                    printf("%d", cnt - 1);
                    return 0;
                }
            }
        }
        
    }
    
    
    cout << cnt << "\n";
}