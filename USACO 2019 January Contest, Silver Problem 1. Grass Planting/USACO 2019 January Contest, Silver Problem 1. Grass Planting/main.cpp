#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector <int> adj[100001];

int minv = 1;

bool vis[100001];

bool good[100001];

int cursum = 0;

void solve(int cur, int pre, int height){
    for(int j: adj[cur]){
        if(!vis[j]){
            vis[j] = true;
            if(good[height - 2]){
                good[height+1] = true;
                solve(j, cur, height + 1);
            }else{
                cursum ++;
                good[height+1] = true;
                solve(j, cur, height + 1);
            }
        }
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    freopen("planting.in","r",stdin); freopen("planting.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    good[2] = true;
    solve(1, -1, 2);
    cout << cursum;
    
}