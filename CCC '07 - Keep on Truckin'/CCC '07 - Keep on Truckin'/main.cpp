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

bool vis[70001];

ll dp[70001];
bool donev[70001];
queue <int> Q;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int a, b;
    scanf("%d%d", &a, &b);
    vis[0] = true;
    vis[990] = true;
    vis[1010] = true;
    vis[1970] = true;
    vis[2030] = true;
    vis[2940] = true;
    vis[3060] = true;
    vis[3930] = true;
    vis[4060] = true;
    vis[4970] = true;
    vis[5030] = true;
    vis[5990] = true;
    vis[6010] = true;
    vis[7000] = true;
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int a;
        scanf("%d", &a);
        vis[a] = true;
    }
    
    dp[0] = 1;
    donev[0] = true;
    Q.push(0);
    while(!Q.empty()){
        int i = Q.front(); Q.pop();
        for(int z = a; z<=b; z++){
            if(vis[i + z]){
                dp[i + z] += dp[i];
                if(!donev[i + z]){
                    donev[i + z] = true;
                    Q.push(i + z);
                }
            }
        }
    
    }
    printf("%lld\n", dp[7000]);
    
    
}