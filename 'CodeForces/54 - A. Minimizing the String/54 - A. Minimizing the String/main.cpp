#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


int main(){
    int asdf;
    cin >> asdf;
    string x;
    cin >> x;
    for(int i = 0; i<x.length()-1; i++){
        if(x[i] - x[i+1] > 0){
            cout << x.substr(0, i) << x.substr(i+1, x.length());
            return 0;
        }
    }
    cout << x.substr(0, x.length()-1);

}