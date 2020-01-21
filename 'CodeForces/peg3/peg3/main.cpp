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

char words[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int arr[5];
bool test[5];

int main(){
    int N;
    cin >> N;
    int num = 1;
    int count = 1;
    int c2 = 0;
    int c3 = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int x = 0; x<arr[2]; x++){
        if(test[2]){
        c3 ++;
        if(c3 == 26){
            c3 = 0;
        }
        }
    for(int z = 0; z<arr[1]; z++){
        if(test[1]){
        c2 ++;
            
        if(c2 == 26){
            c2 = 0;
            test[count] = true;
            count ++;
        }
        }
        for(int i = 0; i<N; i++){
            if(arr[0]==26){
                arr[0] = 0;
                test[count] = true;
                count ++;
            }
            cout << words[arr[0]];
            arr[0] ++;

            if(test[1]){
                cout << words[c2];
            }
            if(test[2]){
                cout << words[c3];
            }
            if(i!=N-1){
                cout << " ";
            }
        }
        
    }

    }
}