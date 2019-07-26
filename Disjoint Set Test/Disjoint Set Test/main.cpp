
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

struct E{int u, v, w;}e[1000000];
int n, m, p[1000000], cnt  =0, mst = 0;

/*
 int p[100001],r[100001];int n,m;
 
 int Find(int x){
 if(p[x] != x){
 p[x] = Find(x);
 }
 return p[x];
 }
 void Link(int x,int y){
 if(r[x] > r[y]){
 p[y] = x;
 }
 else{
 p[x] = y;
 if(r[x] == r[y]){
 r[y]++;
 }
 }
 }
 void Union(int x,int y){
 Link(Find(x),Find(y));
 }

 */

bool cmp(E x, E y){
    return x.w < y.w;
}

pii Find(int d, int count){
    if(d != p[d]){
        p[d] = Find(p[d], count + 1).first;
    }
    pii temp = {p[d], count};
    return temp;
}

vector<int> adj;

bool printer;
int main(){
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        cin >> e[i].u >> e[i].v;
        p[e[i].u] = e[i].u;
        p[e[i].v] = e[i].v;
    }
    for(int i =0; i<m; i++){
        int u = e[i].u, v = e[i].v, w = e[i].w;
        if(cnt == n-1) break;
        pii fu = Find(u, 0), fv = Find(v, 0);
        if(fu.first != fv.first) {
            if(fu.second < fv.second){
                p[fu.first] = fv.first;
            }else{
                p[fv.first] = fu.first;
            }
            adj.push_back(i+1);
            cnt ++;
            mst += w;
        }
        //p[fu] = fv - union (not by rank), add smaller to larger
    }
    int cur = Find(1, 0).first;
    for(int i = 1; i<n; i++){
        if(Find(i, 0).first!=cur){
            cout << "Disconnected Graph";
            return 0;
        }
    }
    while(!adj.empty()){
        printf("%d\n", adj.back());
        adj.pop_back();
    }
}
