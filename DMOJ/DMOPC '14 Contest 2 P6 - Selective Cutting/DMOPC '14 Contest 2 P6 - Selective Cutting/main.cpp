#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct edge{int a; int b; int c; int s;};

bool cmp(edge a, edge b){
    return a.c > b.c;
}

int N, M;

int bit[100001];

pii arr[100001];

edge q[100001];

ll ans[100001];

void update(int x, int num){
    for(;x <= N; x += (x&-x)){
        bit[x] += num;
    }
}

int query(int x){
    int sum = 0;
    for(;x>0; x-=(x&-x)){
        sum += bit[x];
    }
    return sum;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d", &N);
    
    for(int i = 1; i<=N; i++){
        scanf("%d", &arr[i].first);
        arr[i].second = i;
    }
    sort(arr, arr + N + 1);
    scanf("%d", &M);
    for(int i = 0; i<M; i++){
        scanf("%d%d%d", &q[i].a, &q[i].b, &q[i].c);
        q[i].b += 1;
        q[i].s = i;
    }
    sort(q, q + M, cmp);
    
    int curi = N;
    
    for(int i = 0; i<M; i++){
        while(q[i].c <= arr[curi].first && curi >= 1){
            update(arr[curi].second, arr[curi].first);
            curi --;
        }
        ans[q[i].s] = query(q[i].b) - query(q[i].a);
    }
    
    for(int i = 0; i<M; i++){
        printf("%d\n", ans[i]);
    }
    
}