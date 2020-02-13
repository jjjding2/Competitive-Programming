#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;

int arr[130];

int arr1[200005][130];

unordered_set <string> s;

ll pw[200005];

int anum[200005];

int b[200005];
void init(){
    
    pw[0] = 1;
    for(ll i = 1; i<= 200001; i++){
        pw[i] = pw[i - 1]*131;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    init();
    string a;
    string b1;
    cin >> a >> b1;
    int len = (int)a.length();
    
    int len2 = (int)b1.length();
    for(int i = 0; i<len; i++){
        arr[(int)a[i]] ++;
    }
    
    
    for(int i = 97; i<= 122; i++){
        
        for(int z = 0; z<len2; z++){
            b[z] = b1[z];
            if((int)b[z] == i){
                arr1[z][i] ++;
            }
            if(z!=0){
                arr1[z][i] += arr1[z-1][i];
            }
        }
    }
    int ans = 0;
    for(int z = len-1; z<len2; z++){
        bool good  = true;
        for(int i = 97; i<= 122; i++){
            if(z == len-1){
                if(arr1[z][i] - 0 != arr[i]){
                    good = false;
                    break;
                }
            }else{
                if(arr1[z][i] - arr1[z-len][i] != arr[i]){
                    good = false;
                    break;
                }
            }
        }
        
        if(good){
            string x = b1.substr(z-len+1, len);

            if(s.count(x) == 0){
                ans ++;
                s.insert(x);
            }
            
        }
        
    }
    
    cout << ans << "\n";
    
}
