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

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll bit[100001];

ll freq[100001];

ll N, Q, a,b;
ll maxv = 0;

void update(ll x, ll val){
    for(;x <= N; x += (x&-x)){
        bit[x] += val;
    }
}

void updatef(ll x, ll val){
    for(;x <= 100001; x += (x&-x)){
        freq[x] += val;
    }
}

ll query(ll x){
    ll sum = 0;
    for(;x >  0 ; x -= (x&-x)){
        sum += bit[x];
    }
    return sum;
}

ll queryf(ll x){
    ll sum = 0;
    for(;x >  0 ; x -= (x&-x)){
        sum += freq[x];
    }
    return sum;
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> N >> Q;
    for(int i = 1; i<=N; i++){
        cin >> a;
        update(i, a);
        updatef(a, 1);
    }
    
    char type;
    
    
    
    for(int i = 0; i<Q; i++){
        cin >> type;
        if(type == 'C'){
            cin >> a >> b;
            ll test =query(a) - query(a-1);
            update(a, b - test);
            updatef(test, -1);
            updatef(b, 1);
            
        }else if(type == 'S'){
            cin >> a >> b;
            printf("%lld\n", query(b) - query(a-1));
        }else{
            cin >> a;
            printf("%lld\n", queryf(a));
        }
    }
    
}
