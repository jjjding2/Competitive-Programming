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

plu arr[1001];

bool cmp(plu a, plu b){
    return a.second < b.second;
}

int main(){
    ll N, M, K;
    scanf("%lld%lld%lld", &N, &M, &K);
    ll sum = 0;
    for(int i = 0; i<N; i++){
        scanf("%lld%lld", &arr[i].first, &arr[i].second);
        sum += arr[i].first;
    }
    ll required = K * N - sum;
    sort(arr, (arr) + N, cmp);
    ll i = 0;
    ll time = 0;
    while(required > 0){
        if(arr[i].first >= M){
            i ++;
        }else{
            ll temp = min(required, M-arr[i].first);
            time += temp*arr[i].second;
            required -= temp;
            arr[i].first += temp;
        }
    }

    printf("%lld", time);
    
    
    
}