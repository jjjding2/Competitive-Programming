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

vector <pii> adj[100001];

priority_queue<pii,vector <pii>, greater<pii>> q;

int dis[1001];

int dis2[1001];
int N, M;


void dijkstra(int start){
    q.push({0, start});
    pii maxd;
    maxd.first = 0;
    
    memset(dis, INF, sizeof(dis));
    
    dis[start] = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(dis[temp.second] < temp.first){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                q.push({dis[j.first], j.first});
                if(dis[j.first] > maxd.first){
                    
                    if(j.first != N-1 || start != 0){
                        maxd.first = dis[j.first];
                        maxd.second = j.first;
                    }
                }
            }
        }
        
    }
    
}

void dijkstra2(int start){
    q.push({0, start});

    
    memset(dis2, INF, sizeof(dis2));
    
    dis2[start] = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(dis2[temp.second] < temp.first){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis2[j.first] > dis2[temp.second] + j.second){
                dis2[j.first] = dis2[temp.second] + j.second;
                q.push({dis2[j.first], j.first});
            }
        }
        
    }
}

int main(){
    scanf("%d%d", &N, &M);
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijkstra(0);
    dijkstra2(N-1);
    int maxd =0;
    for(int i = 0; i<=N-1; i++){
        if(dis[i] + dis2[i] > maxd){
            maxd = dis[i] + dis2[i];
        }
    }
    printf("%d", maxd);
    
}