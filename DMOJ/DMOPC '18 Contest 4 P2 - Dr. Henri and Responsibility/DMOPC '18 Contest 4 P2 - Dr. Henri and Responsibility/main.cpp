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

bool arr[1000000];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    ll sumv = 0;
    arr[0] = true;
    for(int z = 0;z <n; z++){
        
        int a;
        cin >> a;
        sumv += a;
        for(ll i = sumv; i>= 0; i--){
            if(arr[i - a] == true){
                arr[i] = arr[i - a];
            }
        }
    
    }
    ll minv = INF;
    for(int i = 0; i<=sumv/2; i++){
        if(arr[i] == true && arr[sumv - i] == true && sumv - 2 * i < minv){
            minv = sumv - 2*i;
        }
    }
    cout << minv;
}