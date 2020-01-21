#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pii;
//{v, w}
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        ll final = 0;
        ll a, b, k;
        scanf("%lld%lld%lld", &a, &b, &k);
        if(k == 1){
            cout << a << "\n";
        }else{
        final += ((ll)k/2)*(a-b);
        final += (k%2)*(a);
        cout << final << "\n";
        }
    }
}