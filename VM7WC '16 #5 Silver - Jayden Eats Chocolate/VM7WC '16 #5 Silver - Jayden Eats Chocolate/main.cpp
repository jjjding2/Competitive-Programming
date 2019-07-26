#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

int dp[1000];

int val[1000];

int main(){
    int N;
    scanf("%d%d%d%d", &N, &val[0], &val[1], &val[2]);
    sort(val, val + 3);
    dp[0] = 0;
    for(ll z = 0; z<3; z++){
        for(ll i = 1; i <= N; i++){
            if(i == val[z]){
                dp[i] = max(1, dp[i]);
            }
            else if(i - val[z] >= 0 && dp[i-val[z]]>0){
                dp[i] = max(dp[i - val[z]]+1, dp[i]);
            }
            
        }
    }
    cout << dp[N];
}