#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <pii> adj[2001];

priority_queue <pii, vector <pii>, greater<pii>> q;

int dis[2001];

int main(){
    int N, M, B, Q;
    scanf("%d%d%d%d", &N, &M, &B, &Q);
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    memset(dis, INF, sizeof(dis));
    dis[B] = 0;
    q.push({0, B});
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(dis[temp.second] < temp.first){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                q.push({dis[j.first], j.first});
            }
        }

    }
    for(int i = 0; i<Q; i++){
        int a;
        scanf("%d", &a);
        if(dis[a] == INF){
            printf("-1\n");
        }else{
        printf("%d\n", dis[a]);
        }
    }
}