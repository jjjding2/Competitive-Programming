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

int arr[1000001];
bool vis[1000001];
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA12.txt","r",stdin);
    
    for(int t = 0; t<10; t++){
        int n;
        cin >> n;
        ll maxv = 0;
        for(int z = 0; z<n; z++){
            cin >> arr[z];
            if(arr[z] > maxv){
                maxv = arr[z];
            }
            vis[arr[z]] = true;
        }
        
        unsigned long long ans = 0;
        for(int z = 0; z<n; z++){
            
            for(int x = 2; x*arr[z] <= maxv; x++){
                if(vis[x * arr[z]] == true){
                    ans ++;
                }
            }
            
        }
        cout << ans << "\n";
        memset(arr,0,  sizeof(arr));
        memset(vis, 0, sizeof(vis));
    }
    
}
