#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

string x[10];

char findChar (char a, int b) {
    for (int ia = 0; ia < 10; ia++) {
        if (x[b][ia] == a) {
            return (char) (ia + (int) '0');
        }
    }
    return '1';
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    for (int a = 0; a < 10; a++) {
        cin >> x[a];
    }
    string decode;
    cin >> decode;
    string encode = "";
    int holder = 0;
    for (int a = 0; a < decode.size(); a++) {
        if (a== 0) {
            encode += decode[a];
        }
        else {
            encode += findChar(decode[a], holder);
        }
        holder = (int) encode[a] - (int) '0';
    }
    cout << encode;
}
