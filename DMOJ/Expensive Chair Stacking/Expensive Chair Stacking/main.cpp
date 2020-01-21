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

pii arr[3000004];

ll n, m;

ll solve(ll xv, ll yv){
    ll ans = 0;
    for(int i = 1; i<=n; i++){
        ans += abs(xv - arr[i].first) + abs(yv - arr[i].second);
    }
    return ans;
}

ll maxv(ll a, ll b){
    if(a > b){
        return a;
    }
    else {
        return b;
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin >> n >> m;
    
    ll maxv = 0;
    ll maxi = 0;
    
    for(int i = 1; i<=n; i++){
        int a, b;
        cin >> a >> b;
        arr[i] = {a, b};
        if(a + b > maxv){
            maxv = a + b;
            maxi = i;
        }
    }
    
    ll ans1 = 0;
    if(solve(1, 1) > solve(m, m)){
        ans1 = solve(1, 1);
    }else{
        ans1 = solve(m, m);
    }
    if(solve(1, m) > ans1){
        ans1 = solve(1, m);
    }
    if((solve(m, 1)) > ans1){
        ans1 = solve(m, 1);
    }
    

    cout << ans1;
    
}
