#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

int arr[2001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    
    int n, q;
    scanf("%d%d", &n, &q);
    for(int i = 1; i<=n; i++){
        
        scanf("%d", &arr[i]);
        arr[i] += arr[i - 1];
    }
    for(int z = 0; z<q; z++){
        bool work = false;
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        int lo = l;
        int hi = l;
        int cursum = arr[hi] - arr[lo - 1];
        while(hi <= r && lo <= hi + 1){
            if(cursum < x){
                hi ++;
                cursum = arr[hi] - arr[lo-1];
            }else if(cursum > x){
                lo ++;
                cursum = arr[hi] - arr[lo-1];
            }else if(cursum == x){
                cout << "YES" << "\n";
                work = true;
                break;
            }
            
        }
        if(!work){
            cout << "NO" << "\n";
        }
        
    }
    
}
