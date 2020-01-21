#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> plu;

int arr[3][3];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    
    string temp;
    cin >> temp;
    
    int h = 0;
    int v = 0;
    
    for(int i = 0; i<temp.length(); i++){
        if(temp[i] == 'H'){
            h ++;
            h = h%2;
        }else{
            v ++;
            v = v%2;
        }
    }
    arr[0][0] = 1;
    arr[0][1] = 2;
    arr[1][0] = 3;
    arr[1][1] = 4;
    if(h == 1){
        int temp = arr[0][0];
        arr[0][0] = arr[1][0];
        arr[1][0] = temp;
        
        temp = arr[0][1];
        arr[0][1] = arr[1][1];
        arr[1][1] = temp;
    }
    if(v == 1){
        int temp = arr[0][0];
        arr[0][0] = arr[0][1];
        arr[0][1] = temp;
        
        temp = arr[1][0];
        arr[1][0] = arr[1][1];
        arr[1][1] = temp;
    }
    for(int i = 0; i<2; i++){
        for(int z = 0; z<2; z++){
            cout << arr[i][z] << " ";
        }
        cout << "\n";
    }
    
    
    
    
}