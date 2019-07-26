#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }



const int MM = 100;
int N, M, dis[MM]; vector <pii> adj[MM]; bool vis[MM];

void prim(int st){
    memset(dis, 0x3f, sizeof(dis)); dis[st] = 0;
    for(int i = 1; i<=N; i++){
        int min = 1e9, id = -1;
        for(int j = 1; j<=N; j++){
            if(dis[j]<min && !vis[j]){
                min = dis[j];
                id = j;
            }
        }
        vis[id] = 1;
        for(pii e: adj[id]){
            if(!vis[e.first] && dis[e.first] > e.second)
                dis[e.first] = e.second;
        }
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 1, u, v, w; i<=M; i++){
        scanf("%d%d%d", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    prim(1);
    for(int i= 1; i<=N; i++) printf("%d ", dis[i]);
}