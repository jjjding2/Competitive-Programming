#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[1000001];
int lis[1000001];

int ans;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    memset(lis, INF, sizeof(lis));
    lis[0] = -1*INF;
    for(int i = 0; i<n; i++){
        int low = 0;
        int high = n;
        int mid = (low + high)/2;
        while(low <= high){
            mid = (low + high)/2;
            if(lis[mid] >= arr[i]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        lis[low] = arr[i];
        ans = max(ans, low);
    }
    
    printf("%d", ans);
    
}