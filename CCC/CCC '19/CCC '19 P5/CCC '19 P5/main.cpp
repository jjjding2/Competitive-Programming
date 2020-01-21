#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> plu;

int arr[1001][1001];

queue <pii> q;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n, k;
    scanf("%d%d", &n, &k);
    
    for(int i = 1; i <=n; i++){
        for(int z = 0; z<i; z++){
            scanf("%d", &arr[i][z]);
            if(i <= n - k + 1){
                q.push({i, z});
            }
        }
    }
    
    ll sum = 0;
    while(!q.empty()){
        pii temp = q.front(); q.pop();
        int maxv = 0;
        for(int i = 1; i<=k; i++){
            for(int z = 0; z<=i; z++){
                maxv = max(maxv, arr[i + temp.first][z + temp.second]);
            }
        }
        cout << maxv << " ";
        sum += maxv;
    }
    printf("%lld", sum);
    
    
}