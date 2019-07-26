#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

deque <ll> DQ;
ll arr[1000000];

int main(){
    ll y, x, K;
    scanf("%lld %lld %lld", &y, &x, &K);

    for(int i  = 0; i<K; i++){
        ll temp;
        scanf("%lld", &temp);
        arr[i] = temp;
    }
    sort(arr, arr+K);
    for(int i = 0; i<K; i++){
        DQ.push_front(arr[i]);
    }
    ll curx = 0;
    ll tot = 0;
    while(!DQ.empty() && curx < x){
        ll sum = 0;
        ll first = DQ.front(); DQ.pop_front();
        for(int i = 1; i<y; i++){
            if(!DQ.empty()){
                
                sum += first + i - DQ.back();
                DQ.pop_back();
            }else{
                break;
            }
        }
        curx ++;
        tot += sum;
    }
    cout << tot;
}