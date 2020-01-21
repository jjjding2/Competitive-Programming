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
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

pii arr[100005];

vector <int> arr1[100005];
int close[100005];
int len[100005];

vector <int> maxv;
vector <int> minv;

int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    ll n;
    cin >> n;
    ll ans = 0;

    ll closecnt = 0;
    
    for(int i = 1; i<=n; i++){
        int s;
        cin >> s;
        arr[i].first = INF;
        len[i] = s;
        for(int z = 1; z<=s; z++){
            int a;
            cin >> a;
            if(a > arr[i].first && z != 1 && close[i] ==0){
                close[i] = 1;
                closecnt ++;
            }
            arr[i].first = min(arr[i].first, a);

            arr[i].second = max(arr[i].second, a);

        }
        if(close[i] == 0){
            maxv.push_back(arr[i].second);
            minv.push_back(arr[i].first);
            
        }
        
    }
    sort(minv.begin(), minv.end());

    ans += closecnt*(n-closecnt)*2 + closecnt*(closecnt-1) + closecnt;
    
    for(int i = 0; i<n - closecnt; i++){
        
        int lo = -1;
        ll hi = n-closecnt-1;
        int mi = (lo + hi)/2;
        int spot = -1;
        while(lo<=hi){
            
            mi = (lo + hi)/2;
            if(minv[mi] >= maxv[i] ){
                hi = mi - 1;
            }else if(minv[mi] < maxv[i]){
                lo = mi + 1;
                spot = max(mi,spot);
            }
            
        }
        ans += spot+1;

    }

    cout << ans << "\n";
    
}
