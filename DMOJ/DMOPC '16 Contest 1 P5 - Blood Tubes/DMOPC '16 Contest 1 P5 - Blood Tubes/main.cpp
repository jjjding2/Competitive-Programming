#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 5e5 + 4
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int bit[500004];
void update(int x, int v){
    while(x <= MAXN){
        bit[x] += v;
        x += x&-x;
    }
}

int query(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= x&-x;
    }
    return sum;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    
    int inversion = 0;
    for(int i = 0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        
        
        
    }
    
}
