#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll xv[100000];
ll yv[100000];

int main(){
    ll n;
    scanf("%lld", &n);
    
    ll x, y;

    for(int i = 0; i<n; i++){
        scanf("%lld%lld", &x, &y);
        xv[i] = x;
        yv[i] = y;
    }
    sort(xv, xv + n);
    sort(yv, yv + n);
    x = xv[n/2];
    y = yv[n/2];
    ll sum = 0;
    for(int i = 0; i<n; i++){
        sum += abs(x - xv[i]);
        sum += abs(y - yv[i]);
    }
    cout << sum;
}