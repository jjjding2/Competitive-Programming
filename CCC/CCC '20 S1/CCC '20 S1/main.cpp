#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;

struct e{double t; double d;};
e arr[100005];

bool cmp(e a, e b){
    return a.t < b.t;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        double t, d;
        cin >> t >> d;
        arr[i] = {t, d};
    }
    sort(arr, arr + n, cmp);
    double maxv = 0;
    for(int i = 1; i<n; i++){
        if(abs(arr[i].d - arr[i-1].d)/(abs(arr[i].t - arr[i-1].t)) > maxv){
            maxv =abs(arr[i].d - arr[i-1].d)/(abs(arr[i].t - arr[i-1].t));
        }
        
    }
    cout << maxv << "\n";
    
    
}
