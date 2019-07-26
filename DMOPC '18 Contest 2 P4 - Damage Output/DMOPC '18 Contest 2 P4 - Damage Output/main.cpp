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

ll arr[500001];

int main(){
    ll N, M;
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i<N; i++){
        scanf("%lld", &arr[i]);
        if(arr[i]>=M){
            cout << 1;
            return 0;
        }
    }
    ll first = 0;
    ll sum = arr[0];
    ll min = pow(2, 31)-1;
    for(int i = 1; i<N; i++){
        sum += arr[i];
        while(sum >= M){
            if(i - first + 1 < min){
                min = i-first + 1;
            }
            sum -= arr[first];
            first ++;
        }
    }
    if(min == pow(2, 31)-1){
        cout << "-1";
    }else{
        cout << min;
    }
}