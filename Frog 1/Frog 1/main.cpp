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

int arr[100000];

int dp[100000];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for(int i = 0; i<N; i++){
        for(int z = 1; z<= 2 && i + z < N; z++){
            if(dp[i + z] > abs(arr[i] - arr[i + z]) + dp[i]){
                dp[i + z] = abs(arr[i] - arr[i + z]) + dp[i];
            }
        }
    }
    printf("%d", dp[N-1]);
    
}