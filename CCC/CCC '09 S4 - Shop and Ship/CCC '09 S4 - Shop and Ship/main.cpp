#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000

int INFINITE = 0x3f3f3f3f;

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int N, T, K, D;

queue <pii> Qtemp;
queue <int> Q;

int dis[5001];

vector <pii> adj[5001];

int main(){
    scanf("%d", &N);
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        int x, y, c;
        scanf("%d%d%d", &x, &y, &c);
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }
    scanf("%d", &K);
    for(int i = 0; i<K; i++){
        int x, c;
        scanf("%d%d", &x, &c);
        Qtemp.push({x, c});
        
    }
    scanf("%d", &D);
    
    Q.push(D);
    
    memset(dis, -1, sizeof(dis));
    dis[D] = 0;
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(pii j: adj[temp]){
            if(dis[j.first] == -1 || dis[j.first] > dis[temp] + j.second ){
                dis[j.first] = dis[temp] + j.second;
                Q.push(j.first);
            }
        }
    }
    ll maxv = INFINITY;
    while(!Qtemp.empty()){
        pii temp = Qtemp.front(); Qtemp.pop();
        if(dis[temp.first] + temp.second < maxv){
            maxv = dis[temp.first] + temp.second;
        }
    }
    printf("%lld", maxv);
    
}