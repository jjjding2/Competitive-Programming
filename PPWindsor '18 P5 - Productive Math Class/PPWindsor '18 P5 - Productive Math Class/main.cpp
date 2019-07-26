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
    if(N < 10){
        cout << N;
    }else if(N < 100){
        if(N%2 == 0){
            cout << 1;
        }else{
            cout << (N%10 - 1) / 2;
        }
    }else if(N<1000){
        if((N-120)%3 == 0){
            cout << 1;
        }else{
            N = N%100;
            if(N%2 == 0){
                cout << 1;
            }else{
                cout << (N%10 - 1) / 2;
            }
        }
    }else if(N<10000){
        
    }
}