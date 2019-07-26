#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int n,cnt;
int arr[1001],e[3],dp[1001];

int find(int e1,int e2,int e3,int i){
    if(i == cnt){
        return 0;
    }
    if(arr[i] == 1){
        return min(find(0,e2+e1,e3,i+1)+e1,find(0,e2,e3+e1,i+1)+e1);
    }
    else if(arr[i] == 2){
        return min(find(e2+e1,0,e3,i+1)+e2,find(e2,0,e3+e2,i+1)+e2);
    }
    else{
        return min(find(e1+e3,e2,0,i+1)+e3,find(e1,e2+e3,0,i+1)+e3);
    }
}
int main(){
    //cin.tie(0); cin.sync_with_stdio(0)
    scanf("%d%d%d%d",&e[0],&e[1],&e[2],&n);
    for(int i = 1;i<=n;i++){
        int a;
        scanf("%d",&a);
        if(a != arr[cnt-1] || cnt == 0){
            arr[cnt++] = a;
        }
    }
    printf("%d\n",find(e[0],e[1],e[2],0));
}
