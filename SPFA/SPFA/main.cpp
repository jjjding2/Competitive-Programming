#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int n, m, dis[1001], inf = 0x3f3f3f3f; vector <pii> adj[1001]; bool inq[1001];

void spfa(int st){
    memset(dis, 0x3f, sizeof(dis)); queue<int> q;
    dis[st] = 0; inq[st] = true; q.push(st);
    while(!q.empty()){
        int u = q.front(); q.pop(); inq[u] = false;
        for(pii e: adj[u]){
            int v = e.first, w = e.second;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                if(!inq[v]){q.push(v); inq[v]=true;}
            }
        }
    }
}

int main(){
    
}