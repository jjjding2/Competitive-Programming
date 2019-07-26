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
typedef pair<ll,bool> plu;
typedef map<pii,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct e{int first; int second; int third;};


int x[100001];

int y [100001];

umii extra;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, q;
    scanf("%d%d", &n, &q);
    
    for(int i = 0; i<q; i++){
        int t;
        scanf("%d", &t);
        int a, b;
        scanf("%d%d", &a, &b);
        
        if(t == 1){
            x[a] ++;
            x[a] = x[a];
            y[b] ++;
            y[b] = y[b];
            if(extra.count({a, b}) == 0){
                extra.emplace(make_pair(a, b), 1);
            }else{
                if(extra[make_pair(a, b)] == 1){
                extra[make_pair(a, b)] = 0;
                }else{
                    extra[make_pair(a, b)] = 1;

                }
            }
        }else if(t == 2){
            int temp = x[a] + y[b] + 2;
            temp -= extra[make_pair(a, b)];
;

            printf("%d\n", temp%2);
        }
    }
    
}