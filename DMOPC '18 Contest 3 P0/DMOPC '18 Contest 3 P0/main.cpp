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
    double a1, a2, a3;
    double b1, b2, b3;
    cin >> a1 >> a2 >> a3>> b1 >> b2 >> b3;
    if((int)(sqrt(a1) + 0.9999999) == (int)(sqrt(b1) + 0.9999999) && (int)(sqrt(a2) + 0.9999999) == (int)(sqrt(b2) + 0.9999999) && (int)(sqrt(a3) + 0.9999999) == (int)(sqrt(b3) + 0.9999999)){
        cout << "Dull";
    }else{
        cout << "Colourful";
    }

}