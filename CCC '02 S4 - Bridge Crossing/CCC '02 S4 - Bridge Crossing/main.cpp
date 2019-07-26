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

/*
dp[j] + max{t[j + 1] + t[j + 2]...}

 dp[i] min time to let first people cross the bridge
 
 t[i] holds the times
 
 You consider the case where you group t[i] with t[i - 1], and add with dp[i - 1 - 1]
 
 Constantly track it back
 
 Use another array to keep track of which group he is in
 
 Check every size of a group that includes t[i]
 
 t:     1   5   5   3   3  
 dp: 0  1   5   6   9   9
 
 group  0   0   1   3   3
 
 group[i] means the index of the first member of the group
 
 */
ll dp[5001];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    memset(dp, INFINITY, sizeof(dp));
    
    
}