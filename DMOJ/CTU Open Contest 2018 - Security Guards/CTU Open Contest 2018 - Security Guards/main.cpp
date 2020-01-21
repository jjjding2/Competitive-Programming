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

struct node{int x; int y;};

int psa[5003][5003];
int arr[5003][5003];

int solve(int a, int b){
    
    int lo = 0;
    int hi = 5000;
    int mi = (lo + hi)/2;
    int ans = INF;

        while(lo <= hi){
            mi = (lo + hi)/2;
            
            int aplus = min(a + mi, 5000);
            int bplus = min(b + mi, 5000);
            
            int val = psa[aplus][bplus];
            if( b - mi-1 >= 0){
                val -= psa[aplus][b - mi-1];
            }
            if(a - mi-1 >= 0){
                val -= psa[a - mi-1][bplus];
            }
            if(a - mi-1 >= 0 && b - mi -1>= 0){
                val += psa[a-mi-1][b-mi-1];
            }
            
            if(val> 0){
                hi = mi - 1;
                ans = min(mi, ans);
            }else{
                lo = mi + 1;
            }

        }
        return ans;
    
    
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);


    int n, Q;
    cin >> n >> Q;
    for(int i = 1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;

    }

    for(int i = 0; i<=5001; i++){
        for(int z = 0; z<=5001; z++){
            if(z == 0 && i == 0){
                psa[i][z] = arr[i][z];
            }else if(z == 0){
                psa[i][z] = arr[i][z] + psa[i - 1][z] ;

            }else if(i == 0){
                psa[i][z] = arr[i][z] + psa[i][z-1];
            }else{
            
                 psa[i][z] = arr[i][z] + psa[i - 1][z] + psa[i][z-1] - psa[i - 1][z - 1];
            }
        }
    }

    for(int i = 0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
        
    }
    
    
}
