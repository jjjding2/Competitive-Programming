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
    int val=1;
    int sum = 0;
    int count = 1;
    for(int i = 0; i<= N; i++){
        sum += count *i;
        count ++;
    }
    count = N+1;
    for(int i = 0; i<= N; i++){
        sum += count *i;
        count --;
    }
    cout << sum;
}