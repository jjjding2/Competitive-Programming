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

struct e{int a; int b; int w;};

int arr[100005];

e edge[100005];

bool cmp(e a, e b){
    return a.w > b.w;
}

int p[100005];

int Find(int d){

    if(d != p[d]){
        p[d] = Find(p[d]);
    }
    return p[d];
}

int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i<=n; i++){
        scanf("%d", &arr[i]);
        p[i] = i;
    }
    for(int i = 0; i<m; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edge[i].a = a;
        edge[i].b = b;
        edge[i].w = w;
        
    }
    sort(edge, edge + m, cmp);
    int count = 0;
    int ans = -1;
    for(int i = 1; i<=n; i++){
        while(Find(i) != Find(arr[i])){
            
            int u = Find(edge[count].a), v = Find(edge[count].b);
            if(u!=v){
                p[u] = v;
                ans = edge[count].w;
            }
            count ++;
            
            
        }

    }
    printf("%d", ans);
    
}
