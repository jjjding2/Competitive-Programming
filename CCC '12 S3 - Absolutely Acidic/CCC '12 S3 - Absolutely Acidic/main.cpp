#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int sen[1001];

int max1[1001];

int max2[1001];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        int temp;
        cin >>temp;
        sen[temp] ++;
    }
    
    //index is reading
    
    int max = sen[0];
    int count = 0;
    for(int i = 0; i<1001; i++){
        if(sen[i] > max){
            max = sen[i];
            max1[count] = max;
        }
    }
    
    
    for(int i = 0; i<1001; i++){
        if(sen[i] == max){
            max1[count] = i;
            count ++;
        }
    }
    if(count > 1){
        sort(max1, max1 + count);
        cout << max1[count-1] - max1[0];
        
    }
    //
    else{
        int maxfirst = max1[count-1];
        int maxt = 0;
        count = 0;
        for(int i = 0; i<1001; i++){
            if(sen[i] >= maxt && sen[i] != max){
                maxt = sen[i];
                max2[count] = maxt;
                count ++ ;
            }
        }
        int MAX = 0;
        for(int i = 0; i<1001; i++){
            if(sen[i] == maxt){
                int temp = abs(maxfirst - i);
                if(temp > MAX){
                    MAX = temp;
                }
            }
        }
        cout << MAX;
        
    }
}