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

int dp[1001][1099];
int cost[1001];

queue <pii> q;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &cost[i]);
    }
    q.push({2, 1});
    int minv = INF;
    memset(dp, INF, sizeof(dp));
    dp[2][1] = cost[2];
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        if(cur.first == n && dp[cur.first][cur.second] < minv){
            minv = dp[cur.first][cur.second];
        }
        if(cur.first + cur.second + 1 <= n && dp[cur.first][cur.second] + cost[cur.second + cur.first + 1] < dp[cur.first + cur.second + 1][cur.second + 1]){
            dp[cur.first + cur.second + 1][cur.second + 1] =dp[cur.first][cur.second] + cost[cur.second + cur.first+1];
            //if(cur.first + cur.second + 1== n || (cur.first + cur.second + 1 == 3 && cur.second+1 == 2)){
            //    cout << "hi";
            //}
            q.push({cur.first + cur.second + 1, cur.second + 1});
            
        }
        if(cur.first - cur.second >= 1 && dp[cur.first][cur.second] + cost[cur.first - cur.second] < dp[cur.first-cur.second][cur.second]){
            dp[cur.first-cur.second][cur.second]=dp[cur.first][cur.second] + cost[cur.first - cur.second];

            q.push({cur.first -cur.second, cur.second});
        }
        if(cur.first == n && dp[cur.first][cur.second] < minv){
            minv = dp[cur.first][cur.second];
        }
    }
    printf("%d", minv);
    
    
    
}