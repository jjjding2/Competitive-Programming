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

int dp[100001];

bool vis[100001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N, W;
    scanf("%d%d", &N, &W);
    
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    
    int maxv = 0;
    for(int i = 0; i<N; i++){
        int w, v;
        scanf("%d%d", &w, &v);
        for(int z = N*1000; z >= v; z --){
            if(z - v >=0){
                dp[z] = min(dp[z], dp[z - v] + w);
                
                if(dp[z] <= W && z > maxv){
                    maxv = z;
                }
            }
        }
        
    }
    printf("%d", maxv);
    
    
    
}