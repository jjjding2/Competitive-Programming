#include <bits/stdc++.h>

using namespace std;

int arr[1000001];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
        
    }
    sort(arr, arr + n);
    int count = 0;
    for(int i = 2; i<n; i++){
        if(arr[i] == arr[i - 1]){
            count ++;
            
        }else{
            if(count%2 == 1)
            {
                cout << arr[i];
                
            }
            count = 0;
            
        }
        
    }
}