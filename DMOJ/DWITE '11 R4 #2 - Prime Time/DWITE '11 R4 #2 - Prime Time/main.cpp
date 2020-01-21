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

vector <int> adj;

int arr[1000];

int main(){
    for(int i = 0; i<5; i++){
        int x;
        cin >> x;
        string y = to_string(x);
        bool first = false;
        for(int i = 1; i<=x; i++){
            arr[i-1] = i;
        }
        for(int z = 2; z<=x; z++){
            int freq = 0;
            for(int i = 0; i<x; i++){
                while(arr[i]%z == 0){
                    freq ++;
                    arr[i] = arr[i]/z;
                }
            }
            if(freq != 0){
                if(!first){
                    cout << z << "^" << freq;

                }else{
                    cout << " * " << z << "^" << freq;
                }
                first = true;
            }
        }
        cout << endl;
        memset(arr, 0, sizeof(arr));
    }
}