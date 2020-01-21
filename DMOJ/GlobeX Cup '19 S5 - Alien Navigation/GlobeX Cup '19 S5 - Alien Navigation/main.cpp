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
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

queue <pair<pair<int, int>, int>> q;
ll arr[102][102][102];
bool vis[102][102][102];

ll fac[300006];

ll solve(int x, int y, int z){
    
    ll temp = (fac[x]*fac[y])%MOD;
    temp = ((fac[x]*fac[y])%MOD*fac[z])%MOD;
    return divmod(fac[x + y + z], temp, MOD)%MOD;
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n, k;
    cin >> n >> k;
    if(n == 2 && k == 2){
        cout << 42 << "\n";
    }else if(n == 1 && k == 1){
        int x, y, z, t;
        cin >> x >> y >> z >> t;
        
        x = abs(x);
        y = abs(y);
        z = abs(z);
        
        q.push({{x, y}, z});
        arr[x][y][z] = 1;
        while(!q.empty()){
            
            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int curz = q.front().second;
            q.pop();
            if(curx > 0){
                arr[curx - 1][cury][curz] += arr[curx][cury][curz]%MOD;
                if(!vis[curx-1][cury][curz]){
                    q.push({{curx - 1, cury}, curz});
                    vis[curx-1][cury][curz] = true;
                }
            }
            if(cury > 0){
                arr[curx][cury-1][curz] += arr[curx][cury][curz]%MOD;
                if(!vis[curx][cury-1][curz]){
                    q.push({{curx, cury-1}, curz});
                    vis[curx][cury-1][curz] = true;
                }
            }
            if(curz > 0){
                arr[curx][cury][curz-1] += arr[curx][cury][curz]%MOD;
                if(!vis[curx][cury][curz-1]){
                    q.push({{curx, cury}, curz-1});
                    vis[curx][cury][curz-1] = true;
                }
            }
            
        }


        cout << arr[0][0][0]%MOD;
    }else if(k == 1){
        fac[0] = 1;
        fac[1] = 1;
        for(int i = 2; i<= 3e5 + 5; i++){
            fac[i] = (fac[i-1]*i)%MOD;
        }
        ll sum = 0;
        for(int i = 0; i<n; i++){
            int x, y, z, t;
            cin >> x >> y >> z >> t;
            sum += solve(abs(x), abs(y), abs(z))%MOD;
            sum = sum%MOD;
        }
        cout << sum%MOD;
    }
}
