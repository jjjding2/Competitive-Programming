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


vector <pii> adj[1000001];


priority_queue<pii, vector<pii>, greater <pii> >q;

int dis[1000001];

int cycle[100001];


int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll N, M;
    scanf("%lld%lld", &N, &M);
    
    for(int i = 1; i<=N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[i].push_back({a, 1});
        adj[i].push_back({b, 2});
    }
    
    
    q.push({0, 1});
    
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        
        if(temp.first < dis[temp.second]){
            continue;
        }
        for(pii j: adj[temp.second]){
                dis[j.first] += dis[temp.second] + j.second;
                cycle[j.first] = dis[j.first];
                q.push({dis[j.first], j.first});
            
        }
    }
    
    
    
}