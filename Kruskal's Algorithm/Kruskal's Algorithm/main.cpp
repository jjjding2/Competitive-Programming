#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define endl "\n";


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct E{int u, v, w;}e[100];
int n, m, p[100], cnt  =0, mst = 0;

int dis[100];


bool cmp(E x, E y){
    return x.w < y.w;
}

int Find(int d){
    if(d != p[d]){ p[d] = Find(p[d]);
    }
    return p[d];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    sort(e, e + m, cmp);
    for(int i =0; i<m; i++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(cnt == n-1) break;
        int fu = Find(u), fv = Find(v);
        if(fu != fv) {
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
    cout << mst << endl;
}