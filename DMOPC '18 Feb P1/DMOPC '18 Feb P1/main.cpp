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

bool N[100000];
bool M[100000];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    N[0] = true;
    M[0] = true;
    int i = 0; int r = 0;
    while(n != 0){
        r = n%2;
        N[i++] = r;
        n/=2;
    }
    i = 0;
    while(m != 0){
        r = m%2;
        M[i++] = r;
        m/=2;
    }
    int b = 0;
    int p = 0;
    for(int i = 0; i< k; i++){
        if((N[i] || M[i])&& N[i]!=M[i]){
            b ++;
        }else{
            p ++;
        }
    }
    cout<< b << " " << p;
    
    
}