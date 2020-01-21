#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef  long long ll;
typedef pair<long long, long long> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

//12 point tree DP
vector <int> adj[1000001];


pii dfs(int cur, int pre){


    pii curv;
    curv.first = 1;
    curv.second = 1;
    for(int j: adj[cur]){
        if(j!=pre){
            pii temp = dfs(j, cur);
            curv.first = (curv.first%MOD) * ((temp.first + temp.second + MOD)%MOD);
            curv.second = (curv.second%MOD)* (temp.first%MOD);
        }
    }
    
    return curv;
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;

    for(int i = 0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    pii ans = dfs(1, -1);
    cout << (ans.first + ans.second + MOD)%MOD << "\n";
    
}
