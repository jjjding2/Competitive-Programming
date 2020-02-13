#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unordered_map<string,int> umii;


int arr[130];

int arr1[200005][130];

umii s;

ll pw[200005];

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string a;
    string b;
    cin >> a >> b;
    int len = (int)a.length();
    
    int len2 = (int)b.length();
    for(int i = 0; i<(int)len; i++){
        arr[(int)a[i]] ++;
    }
    
    
    for(int i = (int)'a'; i<= (int)'z'; i++){
        
        for(int z = 0; z<len2; z++){
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
        for(int i = (int)'a'; i<= (int)'z'; i++){
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
            ll cur = 0;
            int c = 0;
            
            if(s.count(b.substr(z-len+1, len)) == 0){
                s.emplace(cur,1);
                ans++;
            }
            
        }
        
    }
    
    cout << ans << "\n";
    
}
