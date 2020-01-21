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
int arr[100000];
int N;

void print(){
    for(int i = 0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
    cin >> N;
    for(int i= 0 ; i<N; i++){
        cin >> arr[i];
    }
    print();
    for(int i = 0; i<N; i++){
        for(int x = 1; x<N; x++){
            if(arr[x-1] > arr[x]){
                int temp = arr[x];
                arr[x] = arr[x-1];
                arr[x-1] = temp;
                print();
            }
        }
    }
}