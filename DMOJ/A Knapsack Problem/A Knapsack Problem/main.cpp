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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
/*
 First consider the best combination for a maximum weight of 5000
 Not one use of each item, and not unlimited
 
 1: n = 2, w = 1, v = 2
 2: n = 2, w = 3, v = 3
 3: n = 3, w = 2, v = 2
 
 Use a cnt array that describes how many times you have used of an item so far, for a certain weight
 Initially all 0
 
 In the 2D array, check the row above and within the same row to the left
 
 0 1 2 3 4 5 6
 0 0 0 0 0 0 0 0
 1 0 2 4 0 0 0 0
 2 1 2 4 4 4 5 6
 3 0
 
 0 1 2 3 4 5 6
 cnt:
 
 dp[i][j] = dp[i - 1][j], dp[i - 1][j - w] + v
 = dp[i][j - w] + v | if cnt[j - w] + 1 <= ni |
 
 You can also implement this using a one dimensional array looping from left to right
 
 if(dp[j - w] + v > dp[j] && cnt[j-w] + 1 <= n){
    dp[j] = dp[j - w] + v;
    cnt[j] = cnt[j - w] + 1;
 }
 
 It is necessary to propagate your answer since the array won't necesarilly be sorted, once you reach the maximum number of items, you have to try looking again
 
 //Alternatively, you could just not be lazy and propagate your answer to the end for every row
 */

ll dp[5001];

int cnt[5001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    memset(cnt, 0, sizeof(cnt));

    for(int z = 0; z < n; z++){
        int n, v, w;
        scanf("%d%d%d", &n, &w, &v);
        for(int i = w; i <= 5000; i++){
            if(dp[i - w] + v > dp[i] && cnt[i - w] + 1 <= n){
                dp[i] = dp[i - w] + v;
                cnt[i] = cnt[i - w] + 1;
            }
        }

        memset(cnt, 0, sizeof(cnt));
    }
    for(int j = 1; j<=5000; j++){
        dp[j] = max(dp[j], dp[j - 1]);
    }
    ll maxv = -99999999;
    for(int z = 0; z<m; z++){
        int a, b;
        scanf("%d%d", &a, &b);
        maxv = max(maxv, dp[a] - b);
    }
    printf("%lld", maxv);
    
    
    
    
    
    
    
    
}