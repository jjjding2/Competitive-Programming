#include <bits/stdc++.h>
using namespace std;
int arr[1000], arr2[1000], sum;
int main(){
    string a, b;
    cin >> a >> b;
    for(int i = 0; i<a.length(); i++)
        arr[(int)a[i]] ++;
    for(int i = 0; i<b.length(); i++)
        arr2[(int)b[i]] ++;
    for(int i = (int)'A'; i<=(int)'Z'; i++)
        sum += max(arr[i] - arr2[i], 0);
    cout << sum << "\n";
}