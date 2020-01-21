#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 10000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int,int>>> q;

queue <int> Q;

vector <pii> adj[MAXN];

int dis[MAXN];

int main(){
    /*
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i =0; i<M; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    Q.push(1);
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(pii j: adj[temp]){
            if(dis[j.first] == -1 || dis[j.first] > dis[temp] + j.second){
                dis[j.first] = dis[temp] + j.second;
                Q.push(j.first);
            }
        }
    }
    for(int i = 1; i<= N; i++){
        if(dis[i] == INT_MAX-1){
            printf("%d\n", -1);
        }else{
            printf("%d\n", dis[i]);
        }
    }
     */
    
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 2; i<=N; i++){
        dis[i] = INT_MAX-1;
    }
    for(int i =0 ; i<M; i++){
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    q.push({0, 1});
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        if(temp.first > dis[temp.second]){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                q.push({dis[j.first], j.first});
            }
        }
    }
    for(int i = 1; i<= N; i++){
        if(dis[i] == INT_MAX-1){
            printf("%d\n", -1);
        }else{
        printf("%d\n", dis[i]);
        }
    }
    
    
}