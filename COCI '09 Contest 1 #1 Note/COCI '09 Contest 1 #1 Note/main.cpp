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


int arr[9];

int main(){
    for(int i = 0; i<8; i++){
        cin >> arr[i];
    }
    bool work = true;
    for(int i = 1; i<8; i++){
        if(arr[i]>arr[i-1]){
            work = false;
            break;
        }
    }
    if(work){
        cout << "descending";
        return 0;
    }
    work = true;
    for(int i = 1; i<8; i++){
        if(arr[i]<arr[i-1]){
            work = false;
            break;
        }
    }
    if(work){
        cout << "ascending";
        return 0;
    }
    cout << "mixed";
}