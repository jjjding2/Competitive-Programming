#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[1000];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i<m; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + m);
    int p1 = 0;
    int p2 = n-1;
    int minv = INF;
    for(int i = 0; i + p2 < m; i++){
        if(arr[p2 + i] - arr[p1 + i] < minv){
            minv = arr[p2 + i] - arr[p1 + i];
        }
    }
    
    printf("%d", minv);
    
}