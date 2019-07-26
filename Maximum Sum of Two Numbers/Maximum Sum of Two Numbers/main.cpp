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

ll arr[100001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    ll N, M;
    scanf("%lld%lld", &N, &M);
    
    for(int i = 0; i<N; i++){
        scanf("%lld", &arr[i]);
    }
    
    sort(arr, arr+N);
    
    ll maxv = 0;
    
    for(int i = 0; i<N; i++){
        int low = 0;
        int high = N;
        int mid = (low + high)/2;
        ll ans = 0;
        while(low <= high){
            if(arr[i] + arr[mid] <= M && mid != i){
                low = mid + 1;
                ans = arr[i] + arr[mid];
            }else{
                high = mid - 1;
            }
            mid = (low + high)/2;
        }
        if(ans > maxv){
            maxv = ans;
        }
    }
    printf("%lld", maxv);
    
    
}