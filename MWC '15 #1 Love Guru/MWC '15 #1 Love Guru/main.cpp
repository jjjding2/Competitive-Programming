#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int main(){
    string x, y;
    cin >> x >> y;
    int val1 = 0;
    int tot;
    for(int z = 0; z<2; z++){
    for(int i = 0; i<x.length(); i++){
        int temp = ((int)tolower(x.at(i)) - 'a' + 1)%10;
        
        int mod = (i+1);
        if(temp == 1){
            val1 += 1;
        }
        else if(temp == 2){
            mod = mod%4;
            if(mod == 1){
                val1 += 2;
            }
            else if(mod == 2){
                val1 += 4;
            }
            else if(mod == 3){
                val1 += 8;
            }
            else if(mod == 0){
                val1 += 6;
            }
        }else if(temp == 3){
            mod = mod%4;
            if(mod == 1){
                val1 += 3;
            }
            else if(mod == 2){
                val1 += 9;
            }
            else if(mod == 3){
                val1 += 7;
            }
            else if(mod == 0){
                val1 += 1;
            }
        }else if(temp == 4){
            mod = mod%2;
            if(mod == 1){
                val1 += 4;
            }else if(mod == 0){
                val1 += 6;
            }
        }else if(temp == 5){
            val1 += 5;
        }else if(temp == 6){
            val1 += 6;
        }else if(temp == 7){
            mod = mod%4;
            if(mod == 1){
                val1 += 7;
            }else if(mod == 2){
                val1 +=9;
            }else if(mod == 3){
                val1 += 3;
            }else if(mod == 0){
                val1 += 1;
            }
        }else if(temp == 8){
            mod = mod%4;
            if(mod == 1){
                val1 += 8;
            }else if(mod == 2){
                val1 += 4;
            }else if(mod == 3){
                val1 += 2;
            }else if(mod == 0){
                val1 += 6;
            }
        }else if(temp == 9){
            mod = mod%2;
            if(mod == 1){
                val1 += 9;
            }else if(mod == 0){
                val1 += 1;
            }
        }
      
        
    }
    val1 = val1%10;
    if(val1 == 0){
        val1 = 10;
    }
        tot += val1;
        val1 = 0;
        x = y;
    }
    cout << tot;
}