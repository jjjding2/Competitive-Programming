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

ll arr[150001];

string median (ll lo, ll hi){
    
    if((lo + hi)%2 == 1){
        ll temp = ( (arr[(lo + hi)/2] + arr[(lo + hi)/2 + 1]) );
        if(temp%2 == 1){
            temp = (temp - 1);
            return to_string((temp)/2) + ".5";

        }else{
            return to_string(temp/2);
        }
    }else{
        return to_string(arr[(lo + hi)/2]);
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll n;
    cin >> n;
    ll maxv = 0;
    ll minv = INF;
    for(ll i =1 ;i<=n; i++){
        cin >> arr[i];
        maxv = max(maxv, arr[i]);
        minv = min(minv, arr[i]);
        
    }
    sort(arr + 1, arr + n + 1);
    //1, 2, 3, 4, 5
    string q1 = "";
    string q2 = "";
    string q3 = "";
    
    
    q1 = median(1, n/2);
    q2 = median(1, n);
    q3 = median(n - n/2 + 1, n);

    cout << minv << " " << maxv << " " << q1 << " " << q2 << " " << q3 << "\n";
    
}
