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
    int N;
    cin >> N;
    int sum;
    for(int i = 1; i<=N; i++){
        if(N%i == 0){
            sum += i;
        }
    }
    cout << sum;
}