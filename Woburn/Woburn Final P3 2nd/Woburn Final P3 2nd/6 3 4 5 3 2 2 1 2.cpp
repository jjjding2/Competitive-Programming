#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

ll arr[4];


int pos[1001];

int nex[1001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0)
    
    scanf("%lld%lld%lld", &arr[1], &arr[2], &arr[3]);
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &pos[i]);
        
    }
    int startv = n-1;
    int curv = pos[n-1];
    while(pos[startv] == curv){
        startv --;
    }
    
    int cur = pos[n-1];
    nex[n-1] = pos[n-1];
    for(int i = n-1; i>= 0; i--){
        if(pos[i] != cur){
            nex[i] = cur;
            
            for(int z = 1; z<= 3; z++){
                if(z != cur && z != pos[i]){
                    nex[i] = z;
                }
            }
            
            cur = pos[i];
        }else{
            nex[i] = nex[i + 1];
        }
    }
    ll tot = 0;

    for(int i = 0; i<n; i++){
            int x = nex[i];
            int y = pos[i];
            arr[x] = arr[x] + arr[y];
            tot += arr[ y ];
            arr[ y ] = 0;
        
    }
    printf("%lld", tot);
    
}

