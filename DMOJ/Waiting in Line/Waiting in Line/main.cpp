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

int N, Q, st, cnt;
map<int, int> pre, nxt, pos; vector <pii> seg;
vector <int> len;
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> N;
    for(int i = 1, x, y; i <=N; i++){
        cin >> x >> y;
        int px = x - 1, nx = x + 1, py = y - 1;
        if(pre.count(x)) px = pre[x];
        if(nxt.count(x)) nx = nxt[x];
        pre[nx] = px; nxt[px] = nx;
        if(pre.count(y)) py = pre[y];
        nxt[py] = x; nxt[x] = y; pre[y] = x; pre[x] = py;
    }
    while(true){
        auto it = nxt.lower_bound(st);
        if(it == nxt.end()) break;
        seg.push_back({st, it->first}); st = it->second;
    }
    seg.push_back({st, 1e9});
    for(pii e: seg){
        pos[e.first] = cnt; cnt += e.second - e.first + 1; len.push_back(cnt);
    }
    cin >> Q;
    for(int i = 1, x; i<=Q; i++){
        char op;
        cin >> op >> x;
        if(op == 'L'){
            x++; int p = lower_bound(len.begin(), len.end(), x) -  len.begin();
            if(p > 0) x-= len[p - 1];
            printf("%d\n", seg[p].first + x -1);
        }else{
            auto it = pos.upper_bound(x); it --;
            printf("%d\n", it->second + x - it->first);
        }
    }
    
}
