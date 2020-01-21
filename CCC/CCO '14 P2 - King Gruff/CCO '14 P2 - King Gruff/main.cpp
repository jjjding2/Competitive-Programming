#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define num 100001


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct edge{int a; int b; int w; int remove;};


vector <pii> adj[num];

vector <pii> adj2[num];


edge e[num];

priority_queue<pii, vector<pii>, greater<pii>> q;

ll disa[num];
ll disb[num];

pii edges[num];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M, a, b;
    scanf("%d%d%d%d", &N, &M, &a, &b);
    
    for(int i = 0; i<M; i++){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        e[i] = {a, b, c, d };
        adj[a].push_back({b, c});
        adj2[b].push_back({a, c});
    }
    
    memset(disa, INF, sizeof(disa));
    memset(disb, INF, sizeof(disb));
    disa[a] = 0;
    disb[b] = 0;

    q.push({0, a});
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(temp.first > disa[temp.second]){
            continue;
        }
        
        for(pii j: adj[temp.second]){
            if(disa[j.first] > disa[temp.second] + j.second){
                disa[j.first] = disa[temp.second] + j.second;
                q.push({disa[j.first], j.first});
            }
        }
        
    }
    
    q.push({0, b});
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(temp.first > disb[temp.second]){
            continue;
        }
        
        for(pii j: adj2[temp.second]){
            if(disb[j.first] > disb[temp.second] + j.second){
                disb[j.first] = disb[temp.second] + j.second;
                q.push({disb[j.first], j.first});
            }
        }
        
    }
    
    memset(edges,INF, sizeof(edges));
    
    for(int i = 0; i<M; i++){
        edge temp = e[i];
        if( disa[temp.a] != INF && disb[temp.b] != INF){
            edges[i] = {disa[temp.a] + disb[temp.b] + temp.w, temp.remove};
        }
    }
    
    sort(edges, edges + M);
    for(int i = 1; i<M; i++){
        edges[i].second += edges[i-1].second;
    }
    
    int query;
    scanf("%d", &query);
    for(int i = 0 ;i<query; i++){
        int D;
        scanf("%d", &D);
        int low = 0;
        int high = M;
        int mid = (low + high)/2;
        int work = -1;
        while(low <= high){
            mid = (low + high)/2;
            if(edges[mid].first <= D && edges[mid].first < INF){
                low = mid + 1;
                work = mid;
            }else{
                high = mid - 1;
            }
        }
        if(work != -1){
            printf("%d\n", edges[work].second);
        }else{
            printf("0\n");
        }
        
        
    }
    
    
}