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
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

const int MV = 1e4 + 4;
struct E{int x, lo, hi, f;};

int N, cnt[2*MV]; vector<E> px, py;
ll ans;
bool cmp(E a, E b){return a.x < b.x || (a.x == b.x && a.f > b.f);};


void solve(){
    sort(px.begin(), px.end(), cmp);
    for(E e: px){
        if(e.f > 0){
            for(int i = e.lo; i<e.hi; i++){
                if(!cnt[i]) ans ++; //cnt[i] is 0
                cnt[i] ++;
            }
        }else{
            for(int i = e.lo; i < e.hi; i++){
                cnt[i] --;
                if(!cnt[i]) ans ++; //if cnt[i] is 0 after changing
            }
        }
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a += MV;
        b += MV;
        c += MV;
        d += MV;
        px.push_back({a, b, d, 1}); px.push_back(E{c, b, d, -1});
        py.push_back({b, a, c, 1}); py.push_back(E{d, a, c, -1});

    }
    solve(); swap(px, py); solve();
    printf("%lld\n", ans);
    
}
