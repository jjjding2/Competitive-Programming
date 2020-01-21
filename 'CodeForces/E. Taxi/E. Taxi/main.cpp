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

int arr[5];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    int ans= 0;
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        arr[a] ++;

    }
    for(int i = 1; i<=1000; i++){
        int x ;

        x = min(arr[1], arr[3]);
        arr[4] += x;
        arr[1] -= x;
        arr[3] -= x;
        
        x = min(arr[1], arr[2]);
        arr[3] += x;
        arr[1] -= x;
        arr[2] -= x;
        
        arr[2] += arr[1]/2;
        arr[1] = arr[1]%2;
        
        arr[4] += arr[2]/2;
        arr[2] = arr[2]%2;
        
    }
    for(int i = 1; i<= 4; i++){
        ans += arr[i];
    }
    printf("%d", ans);
    
}