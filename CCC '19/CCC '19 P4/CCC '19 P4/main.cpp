#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> plu;

int arr[1000001];

int front[1000001];

int back[1000001];


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    
    int n, k;
    scanf("%d%d", &n, &k);
    int maxnum = 0;
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
        if(i == 0){
            front[i] = arr[i];
        }else{
        front[i] = max(front[i - 1], arr[i]);
        }
        maxnum = max(maxnum, arr[i]);
    }
    for(int i = n-1; i>= 0; i--){
        back[i] = max(back[i + 1], arr[i]);
    }
    if(n > k){
        int maxv = 0;
        int maxv2 = 0;

        for(int i = n-k-1; i < n; i++){
            if(i+1> k || n - i-1 > k){
                break;
            }else{
                maxv = front[i];
                maxv2 = back[i + 1];
                maxnum = max(maxnum, maxv + maxv2);
            }
            
        }
        printf("%d", maxnum);
    }else{
        printf("%d", maxnum);
    }
    
}