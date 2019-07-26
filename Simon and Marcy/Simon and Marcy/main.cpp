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

int dp[10001];

pii val[10001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    
    for(int i = 0; i<n; i++){
        scanf("%d%d", &val[i].first, &val[i].second);
    }
    
    for(int i = 0; i<n; i++){
        for(int z = m; z >= val[i].second; z -- ){
            dp[z] = max(dp[z], dp[z - val[i].second] + val[i].first);
        }
    }
    printf("%d", dp[m]);
}
