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

int main(){

    
    ll b;
    cin >> b;
    ll divisors = 0;
        for(ll  z = 1; z<=sqrt(b); z++){
            if(b%z == 0){
                divisors += 2;
                if(z == sqrt(b)){
                    divisors --;
                }


            }
        }

    
    
    cout << divisors;
    
}