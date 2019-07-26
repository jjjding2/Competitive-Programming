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

vector <pii> adj[251];


priority_queue<pii, vector<pii>, greater <pii>> q;

int dis[251];

pii arr[25001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        arr[i].first = a;
        arr[i].second = b;
    }
    
    q.push({0, 1});
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
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
    int mind = dis[N];
    
    int maxv = 0;
    for(int i = 0; i<M; i++){
        memset(dis, INF, sizeof(dis));
        dis[1] = 0;
        q.push({0, 1});
        while(!q.empty()){
            pii temp = q.top(); q.pop();
            if(dis[temp.second] < temp.first){
                continue;
            }
            for(pii j: adj[temp.second]){
                int w= j.second;
                
                if((j.first == arr[i].first && temp.second == arr[i].second)||(j.first == arr[i].second && temp.second == arr[i].first)){
                    w = w * 2;
                }
                if(dis[j.first] > dis[temp.second] + w){
                    dis[j.first] = dis[temp.second] + w;
                    q.push({dis[j.first], j.first});
                }
                
            }
        }
        if(dis[N] > maxv){
            maxv = dis[N];
        }
    }
    printf("%d", maxv - mind);
}









