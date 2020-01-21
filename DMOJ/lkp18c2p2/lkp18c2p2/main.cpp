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

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, k;
    scanf("%d%d", &n, &k);
    
    int temp = 0;
    
    for(int i = 1; i<=n; i++){
        int a;
        scanf("%d", &a);
        temp += (a)%k;
        arr[abs(((temp) + k)%k)] += 1;
        
    }
    
    int sum = arr[0];
    for(int z = 0; z<k; z++){
        if(arr[z] > 1){
            sum += (arr[z]*(arr[z] - 1))/2;
        }
    }
    

        
    
    
    printf("%d", sum);
    
}