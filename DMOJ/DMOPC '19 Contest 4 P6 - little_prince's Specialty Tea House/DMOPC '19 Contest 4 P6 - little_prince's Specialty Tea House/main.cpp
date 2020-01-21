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

ll t[2003];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll n, q;
    cin >> n >> q;
    for(ll i = 1; i<=n; i++){
        cin >> t[i];
    }
    if(n <= 2000 && q <= 2000){
        for(ll i = 0 ;i<q; i++){
            ll type = 0;
            cin >> type;
            if(type == 1){
                ll a;
                cin >> a;
                cout << t[a] << "\n";
            }else if(type == 2){
                ll a, b, t1;
                cin >> a >> b >> t1;
                bool ok = true;
                for(ll z = a; z<=b;z++){
                    if(t[z] - t1< 0){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    for(ll z = a; z<=b; z++){
                        t[z] -= t1;
                    }
                }
            }else if(type == 3){
                ll a, b, t1;
                cin >> a >> b >> t1;
                
                for(ll z = a; z<=b; z++){
                    t[z] = t1 - b + z;
                }
            }else if(type == 4){
                ll a, b;
                cin >> a >> b;
                for(ll z = a; z<=b; z++){
                    t[z] = (ll)sqrt((double)t[z]);
                }
            }

        }
    }else{
        
    }
    
}
