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
    for(int i = 0; i<5; i++){
        string a, b;
        string x;
        getline(cin, a);
        getline(cin, b);
        int count = 0;
        for(int i = 0; i<max(a.length(), b.length()); i++){
            if(a[i] == b[i]){
                count ++;
            }else{
                break;
            }
        }
        cout << count << "\n";
    }
}