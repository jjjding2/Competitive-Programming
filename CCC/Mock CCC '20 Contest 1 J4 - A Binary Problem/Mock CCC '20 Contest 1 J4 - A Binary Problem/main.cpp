#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int arr1[1000005];
int arr2[1000005];

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    string temp;
    cin >> temp;
    int c =0;
    bool good = false;
    for(int i = 0; i<n; i++){
        if(temp[i] == '1'){
            c = 0;
            good = true;
        }else{
            c++;
            arr1[i] = c;
            if(!good){
                arr1[i] = INT_MAX;
            }
        }
    }
     good = false;
    for(int i = n-1; i>=0; i--){
        if(temp[i] == '1'){
            c = 0;
            good = true;
        }else{
            c++;
            arr2[i] = c;
            if(!good){
                arr2[i] = INT_MAX;
            }
        }
    }
    ll ans = 0;
    
    for(int i = 0; i<n; i++){
        ans += min(arr2[i], arr1[i]);
        
    }
    cout << ans << "\n";
    
}
