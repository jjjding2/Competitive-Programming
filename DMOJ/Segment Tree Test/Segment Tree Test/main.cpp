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

int gcf (int a, int b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}



struct node{
    int l;
    int r;
    int min;
    int gcd;
    int num;
    
};

node seg [4005];

void build (int l, int r, int node){
    
    seg[node].l = l; seg[node].r = r;
    if(seg[node].l == seg[node].r){
        scanf("%d", &seg[node].min);
        seg[node].gcd = seg[node].min;
        seg[node].num = 1;
        return;
    }
    int mid = (l + r)/2;
    build(l, mid, node*2); build(mid + 1, r, node*2 + 1);
    seg[node].min = min(seg[node<<1].min,seg[node<<1|1].min);
    seg[node].gcd = gcf(seg[node<<1].gcd, seg[node<<1|1].gcd);
    
    if(seg[node].gcd == seg[node<<1].gcd){
        seg[node].num += seg[node<<1].num;
    }
    if(seg[node].gcd == seg[node<<1|1].gcd){
        seg[node].num += seg[node<<1|1].num;
    }
    
}

void update(int pos, int node, int val){
    if(seg[node].l == seg[node].r){
        seg[node].min = val;
        seg[node].gcd = val;
        seg[node].num = 1;
        return;
    }
    int mid = (seg[node].l+seg[node].r)/2;
    if(pos <= mid) {update(pos,node<<1, val);}
    else{
        update(pos,node<<1|1, val);
    }
    
    seg[node].min = min(seg[node << 1].min, seg[node<<1|1].min);
    seg[node].gcd = gcf(seg[node<<1].gcd, seg[node<<1|1].gcd);
    seg[node].num = 0;
    if(seg[node].gcd == seg[node<<1].gcd){
        seg[node].num += seg[node<<1].num;
    }
    if(seg[node].gcd == seg[node<<1|1].gcd){
        seg[node].num += seg[node<<1|1].num;
    }
}

int queryMin(int l, int r, int node){
    
    int mid = (seg[node].l+seg[node].r)/2;
    
    if(r < seg[node].l || l > seg[node].r){
        return INT_MAX;
    }
    if(l <= seg[node].l && seg[node].r <= r){
        return seg[node].min;
    }
    
    return min(queryMin(l,r,node<<1),queryMin(l,r,node<<1|1));
    
}


int queryGcd(int l, int r, int node){
    if(r < seg[node].l || l > seg[node].r){
        return -1;
    }
    if(l <= seg[node].l && seg[node].r <= r){
        return seg[node].gcd;
    }
    int v1 = queryGcd(l, r, node<<1);
    int v2 = queryGcd(l, r, node<<1|1);
    if(v1 == -1 || v2 == -1){
        return max(v1, v2);
    }else{
        return gcf(v1, v2);
    }
}


int queryNum(int l, int r, int node, int val){
    
    if((r < seg[node].l || l > seg[node].r)){
        return 0;
    }
    if(l <= seg[node].l && seg[node].r <= r){
        if(seg[node].gcd == val){
            return seg[node].num;
        }else{
            return 0;
        }
    }
    
    int v1 = queryNum(l,r,node<<1,val);
    int v2 = queryNum(l,r,node<<1|1,val);
    return v1 + v2;
}
/*
int queryNum(int l, int r, int node, int val){
    if(seg[node].l == seg[node].r ){
        if(seg[node].gcd == val){
            return 1;
        }
        return 0;
        
    }
    
    int mid = (seg[node].l+seg[node].r)/2;
    if(r <= mid){
        return queryNum(l,r,node<<1, val);
    }
    else if(l > mid) {
        return queryNum(l,r,node<<1|1, val);
    }
    else {
        return queryNum(l, mid, node<<1, val) + queryNum(mid+1, r, node<<1|1, val);
    }
}
 */

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    
    int n, q;
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    for(int i = 0; i<q; i++){
        char poop;
        scanf("%c", &poop);

        char type;
        int l, r;

        scanf("%c", &type);
        if(type == 'M'){
            scanf("%d%d", &l, &r);
            printf("%d\n", queryMin(l, r, 1));
        }else if(type == 'C'){
            scanf("%d%d", &l, &r);
            update(l, 1, r);
        }else if(type == 'G'){
            scanf("%d%d", &l, &r);
            printf("%d\n", queryGcd(l, r, 1));

        }else if(type == 'Q'){
            scanf("%d%d", &l, &r);
            int val = queryGcd(l, r, 1);
            printf("%d\n", queryNum(l, r, 1, val));
        }
    }
}
