#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    bool flag = 0;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < n - 1; i++) {
        if(s[i] > s[i + 1]) {
            s.erase(i, 1);
            flag = 1;
            break;
        }
    }
    if(!flag)
        s.erase(n-1, 1);
    cout << s;
}