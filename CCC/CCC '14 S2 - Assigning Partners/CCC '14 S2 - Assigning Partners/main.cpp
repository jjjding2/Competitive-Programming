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
typedef unordered_map<string,string> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

umii a;

string temp[300][2];

int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);

    int n;
    cin >> n;
    bool bad = false;

    for(int i = 1; i<=n; i++){
        
        cin >> temp[i][0];
    }
    for(int i = 1; i<=n; i++){
        cin >> temp[i][1];
        if(temp[i][1] == temp[i][0]){
            bad = true;
        }
    }
    
    
    for(int i = 1; i<=n; i++){
        if(a.count(temp[i][0]) != 0){
            if(a[temp[i][0]]!=temp[i][1] || temp[i][1] == temp[i][0]){
                bad = true;
            }
        }
        if(a.count(temp[i][1]) != 0){
            if(a[temp[i][1]]!=temp[i][0] || temp[i][1] == temp[i][0]){
                bad = true;
            }
        }
        
        a[temp[i][0]] = temp[i][1];
        a[temp[i][1]] = temp[i][0];
    }
    if(bad){
        cout << "bad" << "\n";
    }else{
        cout << "good" << "\n";
    }
    
}
