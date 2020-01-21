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
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

const int MV = 1e6+2;

struct event{int x, lo, hi, v;};
int N, bt[MV], tp[MV]; vector<event> p; long long ans;

bool cmp(event a, event b){return a.x<b.x || (a.x == b.x && a.v < b.v);}

void upd(int bit[], int pos, int val){
    for(int i = pos; i<MV; i += i&-i) bit[i]+= val;
}
int qry(int bit[], int pos){
    int ret = 0;
    for(int i = pos; i; i-=i&-i) ret += bit[i];
    return ret;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d", &N);
    for(int i = 1, a, b, c, d; i <=N; i++){
        scanf("%d%d%d%d", &a, &b, &c, &d);
        p.push_back({a,b,d,1}); p.push_back({c, b, d, -1});
        
    }
    sort(p.begin(), p.end(), cmp);
    for(event &e: p){
        int x = e.x, lo = e.lo, hi = e.hi, v = e.v;
        if(v>0){
            upd(bt, lo, v);
            upd(tp, hi, 1);}
        else{
            ans += qry(bt, hi-1) - qry(tp, lo) - 1;
            upd(bt, lo, v); upd(tp, hi, v); //remove it from the BIT
        }
    }
    printf("%lld\n", ans);
    
}
