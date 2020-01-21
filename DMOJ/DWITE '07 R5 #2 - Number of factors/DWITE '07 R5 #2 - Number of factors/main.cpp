#include <bits/stdc++.h>

using namespace std;

int main() {
    for(int z = 0; z<5; z++){
        int n;
        cin >> n;
        int ans = 0;
        int x = 2;
        int temp = n;
        while(n != 1 && x < n){
            if(temp % x == 0){
                temp = temp / x;
                x = x - 1;
                ans ++;
            }
            x += 1;
        }
        cout << ans<< "\n";
    }
}
