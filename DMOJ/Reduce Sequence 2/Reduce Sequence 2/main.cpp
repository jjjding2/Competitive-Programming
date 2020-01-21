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

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int arr1[501];
int arr2[501];
int dp[501][501];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= a; i++){
        int temp;
        cin >> temp;
        if(i == 0){
            arr1[i] = temp;
        }else{
        arr1[i] = temp + arr1[i - 1];
        }
        
    }
    for(int i = 1; i<=b; i++){
        int temp;
        cin >> temp;
        if(i == 0){
            arr2[i] = temp;
        }else{
            arr2[i] = temp + arr2[i - 1];
        }
        
    }
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i<=a; i++){
        
        for(int z = 1; z<=b; z++){
            
            for(int i1 = 1; i1 <=z; i1++){
                
                for(int z1= 1; z1<=i; z1++){
                    
                    dp[i][z] = min(dp[i][z], dp[a - i1][b - z1] + ( -1*arr1[a - (i - i1)] +arr1[a] - i1)*(-1*arr2[b - (z - z1)] +arr2[b]- z1));
                    
                }
                
            }
            
        }
        
    }
    cout << dp[a][b];
}
