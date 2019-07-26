#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int arr[50001];

int orig[50001];

queue <int> q [5001];

bool vis[5001];


int sum = 0;
int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    memset(arr, INF, sizeof(arr));
    arr[0] = 0;
    for(int i = 1; i<=n; i++){
        scanf("%d", &arr[i]);
        orig[i] = arr[i];
    }
    sort(arr, arr + n+1);
    int i = 1;
    int num = 1;
    while(i != n+1){
        int z = i;
        while((arr[z] == arr[z-1] || z == i) && z != n+1){
            q[arr[z]].push(num);
            z ++;
            if(!vis[num]){
                sum ++;
                vis[num] = true;
            }
            
            num = num%k+1;
            
        }
        if(z - i >k){
            printf("NO");
            return 0;
        }
        i = z;
    }
    if(sum != k){
        printf("NO");
    }else{
        printf("YES\n");
        for(int i = 1; i<=n; i++){
            printf("%d ",q[orig[i]].front());q[orig[i]].pop();
        }
    }
    
}