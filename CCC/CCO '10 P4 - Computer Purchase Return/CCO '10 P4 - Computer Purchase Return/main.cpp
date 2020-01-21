#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF -99999999


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct e{int c; int v;};

e arr[5][1001];

int size[7];

int dp[3001][6];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int T;
    scanf("%d", &T);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int c, v, t;
        scanf("%d%d%d", &c, &v, &t);
        arr[t][size[t]] = {c, v};
        size[t] ++;
    }
    
    int w;
    scanf("%d", &w);
    
    for(int i = 1; i<=T; i++){
        
        for(int z = 0; z<size[i]; z++){
            
            for(int x = w; x >= arr[i][z].c; x--){
                if(dp[x - arr[i][z].c][i - 1]!=0 || i == 1){
                    dp[x][i] = max(dp[x - arr[i][z].c][i-1] + arr[i][z].v, dp[x][i]);
                }
            }
            
        }
    
    }
    
    if(dp[w][T] == 0){
        cout << "-1" << "\n";
    }else{
        cout << dp[w][T] << "\n";
    }
    
    
    
    
    
}