#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    long long count = 0;
    bool work = false;
    for(int i = min(a,b); i>=1; i--){
        if(a % i == 0&& b % i == 0){
            count ++;
        }
        if(count == k){
            cout << i << "\n";
            work = true;
            break;
        }
        
    }
    if(!work){
        cout << "-1" <<"\n";
    }
}
