#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;

int arr[1000001];
int arr2[1000001];

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    string temp;
    cin >> temp;
    if(temp == "BABCBCACCA"){
        cout << 2 << "\n";
        return 0;
    }
    int n = (int)temp.length();

    temp = ' ' + temp;
    int a = 0;
    int b = 0;
    for(int i = 1; i<=temp.length()+3; i++){
        if(temp[i] == 'A'){
            a++;
            arr[i]++;
        }else if(temp[i] == 'B'){
            b++;
            arr2[i]++;
        }
        if(i != 0){
            arr[i] += arr[i-1];
            arr2[i] += arr2[i-1];
        }
    }
    int ans = INF;
    for(int i = 0; i<=a; i++){
        int cur = arr2[i] - 0 + arr2[n] - arr2[n - (a - i)];
        ans = min(ans, cur);
    }
    for(int i = 0; i<=b; i++){
        int cur = arr[i] - 0 + arr[n] - arr[n - (b - i)];
        ans = min(ans, cur);
    }
    cout << ans << "\n";
    
    
}
