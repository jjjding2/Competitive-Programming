#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define endl "\n";
#define INF 0x3f3f3f3f


typedef pair<int, long long> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct E{int u, v, w;}e[200001];
int n, m, p[200001], cnt  =0, mst = 0;

int dis[200001];


bool cmp(E x, E y){
    return x.w > y.w;
}

int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}


vector <pii> adj[2001];

queue <int> q;

ll dist[2001];

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        p[e[i].u] = e[i].u;
        p[e[i].v] = e[i].v;
    }
    sort(e, e + m, cmp);
    for(int i =0; i<m; i++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(cnt == n-1) break;
        int fu = Find(u), fv = Find(v);
        if(fu != fv) {
            adj[u].push_back({v, w});
            if(dis[fu] < dis[fv]){
                p[fu] = fv;
            }else if(dis[fv] < dis[fu]){
                p[fv] = fu;
            }else{
                p[fv] = fu;
                dis[fu] ++;
            }
            cnt ++;
            mst += w;
        }
        //p[fu] = fv - union (not by rank), add smaller to larger
    }
    q.push(1);
    memset(dist, INF, sizeof(dist));
    dist[1] = 0;
    while(!q.empty()){
        int temp = q.front(); q.pop();
        for(pii j: adj[temp]){
            if(dist[j.first] > dist[temp] + j.second){
                dist[j.first] = dist[temp] + j.second;
                q.push(j.first);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        printf("%lld\n", dist[i]);
    }
}