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

deque <int>maxv;

deque <int> minv;

int arr[3000003];

//monodeque ?

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    int l = 1;
    int r = 1;
    ll ans = 0;
    while(r <= n && l <= n){
        while(!maxv.empty() && maxv.back() < arr[r]){ maxv.pop_back();}
        while(!minv.empty() && minv.back() > arr[r]) {minv.pop_back();}

            maxv.push_back(arr[r]);
        
            minv.push_back(arr[r]);
        

            while(maxv.front() - minv.front() > k){
                if(maxv.front() == arr[l]){
                    maxv.pop_front();
                }
                if(minv.front()==arr[l]){
                    minv.pop_front();
                }
                l ++;
            }
            ans += r - l + 1;
        r ++;
    }
    printf("%lld\n", ans);
    
    
}
