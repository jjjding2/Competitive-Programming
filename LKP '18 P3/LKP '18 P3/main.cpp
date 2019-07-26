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

    unsigned long long N;
    cin >> N;
    if(N >= 4){
        if(N%2 == 0){
            cout << (unsigned long long)(N)*N/2;
        }else{
            cout << (unsigned long long)(N + 1)*(N-1)/2;
        }
    }else{
        if(N == 3){
            cout << 2;
        }else if(N == 2){
            cout << 1;
        }else if(N == 1){
            cout << 0;
        }
    }
}