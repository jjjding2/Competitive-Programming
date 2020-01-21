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

queue <int> q;
stack <int> sta;
int n;
int s;
vector <int> adj[5010];
int dis[5010];
int pre[5010];

bool vis[5010];
int in[5010];
int work;

void dfs (int cur, int pre, int maxd){
    
    if(maxd == 0){
        return;
    }
    for(int j: adj[cur]){
        if(j != pre){
            if(!vis[j]){
                work --;
            }
            vis[j] = true;
            dfs(j, cur, maxd - 1);

            
        }
    }
    
}

bool solve(int d, int start){
    dis[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int temp = q.front(); q.pop();
        for(int j: adj[temp]){
            if(dis[j] > dis[temp] + 1){
                dis[j] = dis[temp] + 1;
                sta.push(j);
                q.push(j);
                pre[j] = temp;
            }
        }
    }
    int soldier = 0;
    pre[start] = -1;
    while(!sta.empty()){
        int temp = sta.top(); sta.pop();
        if(!vis[temp]){
            int point = temp;
            for(int i = 0; i<d; i++){
                point = pre[point];
            }
            if(!vis[point]){
                work --;
            }
            vis[point] = true;

            dfs(point, -1, d);
            soldier ++;
        }
        if(soldier == s){
            break;
        }
    }
    memset(dis, INF, sizeof(dis));
    memset(vis, false, sizeof(vis));
    memset(pre, 0, sizeof(pre));
    if(work == 0){
        return true;
    }else{
        return false;
    }
    return false;
}


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    memset(dis, INF, sizeof(dis));

    scanf("%d%d", &n, &s);
    if(n == s){
        cout << 0;
        return 0;
    }
    work = n;
    for(int i = 0; i<n-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        in[a] ++;
        in[b] ++;
    }
    int start = 1;
    for(int i = 1; i<=n; i++){
        if(in[i] == 1){
            start = i;
        }
    }
    
    int minv = 0;
    int maxv = n + 10;
    int cur;
    int ans;
    while(minv <= maxv){
        cur = (minv + maxv)/2;
        if(solve(cur, start)){
            maxv = cur - 1;
            ans = cur;
        }else{
            minv = cur + 1;
        }
        work = n;
    }
    printf("%d", ans);
}
