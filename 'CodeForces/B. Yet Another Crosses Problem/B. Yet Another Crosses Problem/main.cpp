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

int ver[50001];
int hor[50001];
bool arr[400002];
int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int z = 0; z<n; z++){
            string a;
            cin >> a;
            for(int x = 0; x<m; x++){
                if(a[x] == '.'){
                    arr[m*z+x] = 1;
                    ver[x]++;
                    hor[z]++;
                }
            }
        }
        int v1 = INF;
        for(int z = 0; z<n; z++){
            
            for(int x = 0; x<m; x++){
                int cur = ver[x] + hor[z];
                cur -= arr[m*z + x];
                v1 = min(cur, v1);
            }
            
        }
        cout << v1 << "\n";
        for(int i = 0; i<n*m; i++){
            arr[i] = 0;
            
        }
        for(int z = 0; z<n; z++){
            hor[z] = 0;
        }
        for(int z = 0; z<m; z++){
            ver[z] = 0;
        }

    }

}