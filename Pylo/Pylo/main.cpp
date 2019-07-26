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

queue <pii> q;

bool vis[21][21];

pii ans[21][21];

int r, c;

pii val;

bool dfs(pii temp, bool label[21][21], int count, pii path[]){
    if(count == r*c){
        return true;
    }
    
    for(int i = 1; i<= r; i++){
        for(int z = 1; z<= c; z++){
            if(label[i][z] == 0 &&!vis[i][z] && temp.first != i && temp.second != z && temp.first - temp.second != i - z && temp.first + temp.second != i + z){
                label[i][z] = 1;
                path[count] = {i, z};

                if(dfs({i, z}, label, count + 1, path)){
                    return true;
                }
                path[count] = {0, 0};
                label[i][z] = 0;
                
            }
            
        }
        
    }

    return false;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int T;
    scanf("%d", &T);
    for(int t = 0; t<T; t++){
        scanf("%d%d", &r, &c);
        int tot = r*c;
        pii *path = new pii[r*c];
        tot --;
        bool good = false;
        for(int i = 1; i<= r; i++){
            for(int z = 1; z<= c; z++){
                if(dfs({i, z}, vis, 0, path)){
                    good = true;
                    pii temp = {i, z};
                    cout << "Case #" << t + 1 << ": " << "POSSIBLE" << "\n";

                    for(int x = 0; x< r*c; x++){
                        cout << path[x].first << " " << path[x].second << "\n";
                        
                    }
                    break;
                }
            }
            if(good){
                break;
                
            }
            
        }
        if(!good){
        cout << "Case #" << t + 1 << ": " << "IMPOSSIBLE" << "\n";
        }
        memset(vis, false, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        
    }
    
}
