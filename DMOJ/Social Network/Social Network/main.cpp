#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<string,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

umii names;

int p[200005];

int sz[200005];

int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    int c = 0;
    for(int i = 0; i<min(200005, (n + 1)*2); i++){
        p[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i<n; i++){
        string a, b;
        cin >> a >> b;
        if(names.count(a) == 0){
            names.emplace(a, c);
            c++;
        }
        if(names.count(b) == 0){
            names.emplace(b, c);
            c++;
        }
        
        int av = names.at(a);
        int bv = names.at(b);
        int pa = Find(av); int pb = Find(bv);
        if(pa != pb){
            p[pa] = pb;
            sz[pb] += sz[pa];
        }
        cout << sz[pb] << "\n";
    }
    
}
