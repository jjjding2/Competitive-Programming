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

int arr[2001][2001];

bool ver[2001];
bool hor[2001];


deque <pii> adj;

int main(){
    //cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    int c = 0;
    for(int i = 0; i<n; i++){
        for(int z = 0; z<n; z++){
            cin >> arr[i][z];
            if(arr[i][z] == 1){
                c ++;

                adj.push_back({i,z});
            }
        }
    }
    int m = 0;
    while(!adj.empty()){
        pii t = adj.front(); adj.pop_front();
        if(arr[t.first][t.second]==1){
            if(!ver[t.first]){
                ver[t.first] = true;
                for(int z = 0; z<n; z++){
                    arr[t.first][z] = (arr[t.first][z]+1)%2;
                    if(arr[t.first][z] == 1){
                        adj.push_front({t.first,z});
                    }
                }
                m++;
            }else if(!hor[t.second]){
                hor[t.second] = true;
                for(int z = 0; z<n; z++){
                    arr[z][t.second] = (arr[z][t.second]+1)%2;
                    if(arr[z][t.second]==1){
                        adj.push_front({z,t.second});
                    }
                }
                m++;
            }
            /*
            for(int i = 0; i<n; i++){
                for(int z = 0; z<n; z++){
                    cout << arr[i][z] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
            */
            
        }
    }
    for(int i = 0; i<n; i++){
        for(int z = 0; z<n; z++){
            if(arr[i][z] == 1){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << m << "\n";
    for(int i = 0; i<n; i++){
        if(hor[i]){
            cout << "C " << (i+1) << "\n";
        }
    }
    for(int i = 0; i<n; i++){
        if(ver[i]){
            cout << "R " << (i+1) << "\n";
        }
    }

}
