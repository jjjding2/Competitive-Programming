#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, double> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double,int> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <pii> adj[1001];

priority_queue <pair<double, int>, vector <pair<double, int>>, greater<pair<double,int>>> q;
double dis[10001];
int edges[10001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i<M; i++){
        int a, b;
        double c, d;
        scanf("%d%d%lf%lf", &a, &b, &c, &d);
        adj[a].push_back({b, c/d});
        adj[b].push_back({a, c/d});
    }
    q.push({0, 1});
    for(int i = 0; i<=N+1; i++){
        dis[i]= 9999999999.0;
        edges[i] = 99999999;
    }
    edges[1] = 0;
    
    dis[1] = 0;
    while(!q.empty()){
        plu temp = q.top(); q.pop();
        
        if(dis[temp.second] < temp.first){
            continue;
        }
        
        for(pii j: adj[temp.second]){
            
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                edges[j.first] = edges[temp.second] + 1;
                q.push({dis[j.first], j.first});
            }else if(dis[j.first] == dis[temp.second] + j.second && edges[j.first] > edges[temp.second] + 1){
                edges[j.first] = edges[temp.second] + 1;
                q.push({dis[j.first], j.first});

            }
            
        }
    
    }
    
    printf("%d\n", edges[N]);
    printf("%d", (int)round((dis[N]/0.75 - dis[N])* 60.0) );
}