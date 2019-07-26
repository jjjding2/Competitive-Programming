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

struct node{
    node *ch[2]; int idx;
    node(){ch[0]=ch[1]=nullptr; idx = 1e9;}
    
};
int N, Q, q, mask = 1<<30; node*root;

void ins(node *cur, int x, int idx, int mask){
    if(!mask) {cur ->idx = min(cur->idx, idx); return;}
    int bit = (x&mask) > 0;
    if(!cur->ch[bit]) cur->ch[bit] = new node();
    ins(cur->ch[bit], x, idx, mask>>1);
    
}

int qry(node *cur, int x, int mask){
    if(!mask) return cur->idx;
    int bit = (x&mask)>0;
    if(cur->ch[bit]) return qry(cur->ch[bit], x, mask>>1);
    return qry(cur->ch[!bit], x, mask>>1);
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &N, &Q); root = new node();
    for(int i = 0, x; i<N; i++){
        scanf("%d", &x); ins(root, x, i, mask);
    }
    for(int i = 0, x; i<Q; i++){
        scanf("%d", &x); q^=x;
        printf("%d\n", qry(root, q, mask));
        
    }
    
    
}
