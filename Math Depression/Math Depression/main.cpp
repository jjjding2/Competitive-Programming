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

int main(){
    ll N;
    scanf("%lld", &N);
    ll N1 = N;
    ll product = 1;
    while((int)N1-4 > 0){
        N1 = N1 - 3;
        product = (product * 3)%1000000007;
    }
    product = product * N1;
    cout << product%1000000007;
}