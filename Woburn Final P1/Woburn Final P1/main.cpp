#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<ll, ll> pii;
typedef unsigned long long ull;
map<ll, ll> um;

int arr[101];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0)
    int n;
    scanf("%d", &n);
    ll m1 = 0;
    ll m2 = 0;

    for(int i = 0; i<n; i++){
        ll a;
        scanf("%lld",&a);
        if(!um.count(a)){um[a] = 0;}
        um[a]++;
        
    }
    int cnt = 0;
    for(pii temp:um){
        arr[cnt++] = temp.second;
    }
    sort(arr,arr+cnt);
    printf("%d", arr[cnt-1] + arr[cnt - 2]);
}
