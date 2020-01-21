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

struct edge{int a; int b; int w;};

edge edges[200001];
int N, M;

vector <pii> adj[200001];

vector <pii> adj2[200001];

priority_queue<pii, vector<pii>, greater<pii>> q;

ll dis1[200001];
ll dis2[200001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d%d", &N, &M);
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
        adj[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    
    q.push({0, 1});
    
    memset(dis1, INF, sizeof(dis1));
    memset(dis2, INF, sizeof(dis2));
    
    dis1[1] = 0;
    dis2[N] = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(temp.first > dis1[temp.second]){
            continue;
        }
        for(pii j: adj[temp.second]){
            if(dis1[j.first] > dis1[temp.second] + j.second){
                dis1[j.first] = dis1[temp.second]+ j.second;
                q.push({dis1[j.first], j.first});
            }
        }
    }
    
    q.push({0, N});
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(temp.first > dis2[temp.second]){
            continue;
        }
        for(pii j: adj2[temp.second]){
            if(dis2[j.first] > dis2[temp.second] + j.second){
                dis2[j.first] = dis2[temp.second]+ j.second;
                q.push({dis2[j.first], j.first});
            }
        }
    }
    ll curdis = dis1[N];
    ll wew = INF;
    bool work = false;
    for(int i = 0; i<M; i++){
        ll test = dis1[ edges[i].a ] + dis2[ edges[i].b ] + edges[i].w;
        
        if(test > curdis && test < wew){
            wew = test;
            work = true;
        }
        
    }
    if(!work){
        printf("-1\n");
    }else{
        printf("%lld\n", wew);
    }
    
    
}