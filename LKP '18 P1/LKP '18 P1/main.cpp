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

ll arr[100];




int main(){
    int N;
    cin >> N;
    ll K;
    cin >> K;
    for(int i = 0; i<N; i++){
        scanf("%lld", &arr[i]);
    }
    ll count = 0;
    for(int i = N-1; i>= 0; i--){
        while(arr[i]<=K){
            K = K - arr[i];
            count ++;
        }
    }
    if(K > 0){
        cout << "-1" << "\n";
    }else{
        cout << count << "\n";
    }
    

}