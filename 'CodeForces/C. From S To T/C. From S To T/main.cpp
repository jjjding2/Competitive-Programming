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

int arr1[30];


int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int t;
    cin >> t;
    while(t--){
        
        string a, b, c;
        cin >> a >> b >> c;
        int cur = 0;
        for(int i = 0; i<b.length(); i++){
            arr1[b[i] - 'a']++;
            if(b[i] == a[cur]){
                arr1[a[cur] - 'a']--;
                cur ++;
            }
            
        }
        if(cur < a.length()){
            cout << "NO" << "\n";
        }else{
            for(int i = 0; i<c.length(); i++){
                arr1[c[i] - 'a']--;
            }
            bool work = true;
            for(int i = 0; i<= 'z' - 'a'; i++){
                if(arr1[i] > 0){
                    work = false;
                    break;
                }
            }
            if(work){
                cout << "YES" << "\n";
            }else{
                cout << "NO" << "\n";
            }
        }
        memset(arr1, 0, sizeof(arr1));
        
    }
    
}
