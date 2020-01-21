#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<long long, long long> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct edge{ll a; ll b; ll c; ll d;};

bool cmp(edge a, edge b){
    return a.c < b.c;
}

int N, Q;


pii arr[200001];
ll bit[200001];

ll psa[200001];
ll ans[200001];

edge q[200001];

ll query(ll x){
    ll sum = 0;
    for(; x > 0; x-= (x&-x)){
        sum += bit[x];
    }
    return sum;
}

void update(ll x, ll num){
    for(; x <= N; x += (x&-x)){
        bit[x] += num;
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &N, &Q);
    ll tot = 0;
    for(int i = 1; i<=N; i++){
        scanf("%lld", &arr[i].first);
        arr[i].second = i;
        psa[i] = psa[i - 1] + arr[i].first;
        tot += arr[i].first;
    }
    sort(arr, arr + N + 1);
    
    for(int i = 0; i<Q; i++){
        scanf("%lld%lld%lld", &q[i].a, &q[i].b, &q[i].c);
        q[i].d = i;
        q[i].a --;
    }
    sort(q, q + Q, cmp);
    
    int curi = 1;
    
    for(int i = 0; i<Q; i++){
        while(q[i].c > arr[curi].first && curi <= N){
            update(arr[curi].second, arr[curi].first);
            curi ++;
        }
        ans[q[i].d] = psa[q[i].b] - psa[q[i].a] - 2*(query(q[i].b) - query(q[i].a));
    }
    for(int i = 0; i<Q; i++){
        printf("%lld\n", ans[i]);
    }
    
    
    
    
    
    
}