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
    int x;
    int y;
    cin >> x >> y;
    for(int z = 1; z<=y; z++){
        if(z%2 == 1){
        for(int i = 1; i<=x; i++){
            if(i%2 == 1){
                cout << "0";
            }else{
                cout << "1";
            }
        }
        }else{
            for(int i = 1; i<=x; i++){
                if(i%2 == 1){
                    cout << "1";
                }else{
                    cout << "0";
                }
            }
        }
        cout << "\n";
    }
}