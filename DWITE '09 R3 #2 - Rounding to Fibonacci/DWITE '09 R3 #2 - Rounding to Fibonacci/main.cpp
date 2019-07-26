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

ll fib [100];
int main(){
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i<52; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    for(int i = 0; i<5; i++){
        ll N;
        scanf("%lld", &N);
        int count = 0;
        while(fib[count]< N){
            count ++;
        }
        if(abs(fib[count] - N ) <= abs(fib[count-1]-N)){
            cout << fib[count] << endl;
        }else{
            cout << fib[count -1] << endl;
        }
    }
}