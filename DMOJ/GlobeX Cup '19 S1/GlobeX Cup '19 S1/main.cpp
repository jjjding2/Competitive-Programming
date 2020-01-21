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
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

umii s;

int arr[100005];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    cin >> n >> k;
    int val = 0;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        if(s.find(x)){
            cout << 0 << "\n";
            s.emplace(x, val);
            arr[val] = 1;
            val ++;
            
        }else{
            int y = s.at(x);
            cout << arr[y] << "\n";
            arr[y] ++;
        }
    }
    

    cout << val << "\n";
    
}