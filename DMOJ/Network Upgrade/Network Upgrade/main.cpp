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

struct edge{int a; int b;
    int c1; int c2;
};
bool cmp1(edge a, edge b){
    if(a.c1 == b.c1){
        return a.c2 < b.c2;
    }
    return a.c1 < b.c1;
    
}
bool cmp2(edge a, edge b){
    if(a.c2 == b.c2){
        return a.c1 < b.c1;
    }
    return a.c2 < b.c2;
}
edge arr[20005];

int p[10005];

int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i<m ;i++){
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = {a, b, c, d};
        
    }
    for(int i = 1; i<=n; i++){
        p[i] = i;
    }
    sort(arr, arr + m, cmp1);
    

    
    int edges = 0;
    int ans = 0;
    for(int i = 0; i<m; i++){
        if(edges == k){
            break;
        }
        int a = arr[i].a;
        int b = arr[i].b;
        ans = max(ans, arr[i].c1);
        int fa = Find(a);
        int fb = Find(b);
        if(fa != fb){
            p[fa] = fb;
            edges ++;
        }
    }
    sort(arr, arr + m, cmp2);
    for(int i = 0; i<m; i++){
        if(edges == n-1){
            break;
        }
        int a = arr[i].a;
        int b = arr[i].b;
        ans = max(ans, arr[i].c2);

        int fa = Find(a);
        int fb = Find(b);
        if(fa != fb){
            p[fa] = fb;
            edges ++;
        }
    }
    cout << ans;
    
    
}
