#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll arr[100];
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%lld", &arr[i]);
    }
    for(int i = 0; i<N; i++){
        ll x = arr[0];
        ll y = arr[i];
        arr[0] = gcd(x, y);
    }
    ll prime = arr[0];
    ll max = 0;
    while(prime%2==0){
        prime = prime/2;
        max = 2;
    }
    while(prime!=1){
        bool fail = true;
        for(int i = 3; i<=sqrt(prime); i+=2){
            if(prime%i==0){
                fail = false;
                prime = prime/i;
                if(i>max){
                    max = i;
                }
                break;
            }
        }
        if(fail){
            if(prime>max){
                max = prime;
            }
            break;
        }
    }
    if(max == 0){
        cout << "DNE";
    }else{
        cout << max;
    }
}