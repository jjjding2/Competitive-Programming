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

ll arr[501][501];

ll ans[501][501];

queue <pii> q;

int d[2][2] = {{0, 1},{1, 0}};

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    cin >> n >> m;
    for(int i =0 ; i<n; i++){
        for(int z = 0; z<m; z++){
            cin >> arr[i][z];
        }
    }
    memset(ans, INF, sizeof(ans));
    
    ans[0][0] = arr[0][0];
    
    q.push({0, 0});
    while (!q.empty()) {
        
        pii temp = q.front(); q.pop();
        
        for(int i = 0; i<2; i++){
            
            int tempx = temp.first + d[i][0];
            int tempy = temp.second + d[i][1];
            
            if(tempx < n && tempy <m){
                if(ans[tempx][tempy] > ans[temp.first][temp.second] + arr[tempx][tempy]){
                    ans[tempx][tempy] = ans[temp.first][temp.second] + arr[tempx][tempy];
                    q.push({tempx, tempy});
                }
            }
            
        }
        
    }
    
    cout << ans[n - 1][m-1];
    
    
}
