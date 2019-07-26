#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int N;

int main(){
    scanf("%d", &N);
    int max1= 0;
    int min1 = 101;
    int max2 = 0;
    int min2 = 101;
    for(int i = 0; i<N; i++){
        int x, y;
        scanf("%d", &x);
        scanf("%d", &y);
        
        if(x > max1){
            max1 = x;
        }
        if(x < min1){
            min1 = x;
        }
        
        if(y > max2){
            max2 = y;
        }
        if(y < min2){
            min2 = y;
        }
    }
    cout << pow(max(max1 - min1, max2 - min2), 2);
}