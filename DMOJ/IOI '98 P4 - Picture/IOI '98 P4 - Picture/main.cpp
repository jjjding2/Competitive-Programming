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
ll fpow (ll a, ll b, ll mod) {if (b == 0) {return 1;} if (b % 2 == 0) {ll temp = fpow (a, b/2, mod);return (temp*temp)%mod;} return fpow (a, b - 1, mod)*a;}
ll divmod(ll i, ll j, ll mod){i%=mod; j%=mod;return i*fpow(j,mod-2,mod)%mod;}

struct event{int x; int yl; int yh; int val;};
ll ans = 0;
vector <event> adj;
vector <event> adj2;


bool cmp(event a, event b){
    if(a.x == b.x){
        return a.val > b.val;
    }
    return a.x < b.x;
}

int arr[20100];

// line sweep perimeter

void solve(){
    sort(adj.begin(), adj.end(), cmp);
    for(event temp: adj){
        int x = temp.x; int y1 = temp.yl; int y2 = temp.yh; int val = temp.val;
        
        for(int i = y1; i<y2; i++){
            if(val == 1){
                if(arr[i] == 0){
                    ans ++;
                }
                arr[i] += 1;
            }else{
                if(arr[i] == 1){
                    ans ++;
                }
                arr[i] -= 1;
            }
        }
    }
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += 10004;
        y1 += 10004;
        x2 += 10004;
        y2 += 10004;
        adj.push_back({x1, y1, y2, 1});
        adj.push_back({x2, y1, y2, -1});

        adj2.push_back({y1, x1, x2, 1});
        adj2.push_back({y2, x1, x2, -1});
    }
    solve(); swap(adj, adj2);
    solve();
    cout << ans;
    
}
