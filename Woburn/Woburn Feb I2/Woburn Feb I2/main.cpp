#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

queue <pii> q;

deque <pii> lv;
queue <pii> rv;

struct e{int p; int l; int g;};

e arr[1001];

bool cmp(e a, e b){
    return a.p < b.p;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    
    int pos, L;
    scanf("%d%d", &pos, &L);
    
    for(int i = 0; i<n; i++){
        int p, l, g;
        scanf("%d%d%d", &p, &l, &g);
        arr[i] = {p, l, g};

    }
    sort(arr, arr + n, cmp);
    for(int i = 0; i<n; i++){
        int p = arr[i].p;
        int l = arr[i].l;
        int g = arr[i].g;
        if(p == pos){
            if(L >= l){
                L += g;
            }else{
                printf("%d", L);
                return 0;
            }
        }else if(p < pos){
            lv.push_back({l, g});
        }else{
            rv.push({l, g});
        }
    }
    
    while((!lv.empty()&&L >= lv.back().first)|| (!rv.empty() &&L >= rv.front().first)){
        if(!lv.empty() && L >= lv.back().first){
            L+=lv.back().second;
            lv.pop_back();
        }
        if(!rv.empty() && L >= rv.front().first){
            L+= rv.front().second;
            rv.pop();
        }
    }
    cout << L;
    
    
}