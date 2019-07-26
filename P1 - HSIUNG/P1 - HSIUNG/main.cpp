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

#define maxv 1000

int dp[maxv];
int v[3];
int main(){
    int a;
    scanf("%d%d%d", &v[0], &v[1], &a);
    int maxi = 0;
    sort(v, v+2);
    for(int z = 0; z<2; z ++ ){
        for(int i = min(v[0], v[1]); i<=a; i++){
            if(i == v[z]){
                dp[i] = max(1, dp[i]);
                if(i > maxi){
                    maxi = i;
                }
            }else if(dp[i - v[z]] != 0){
                dp[i] = max(1 + dp[i-v[z]], dp[i]);
                if(i > maxi){
                    maxi = i;
                }
            }
        }
    }
    cout << maxi;
}