#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define endl "\n";
#define INF 0x3f3f3f3f


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

//longest cycle in a graph

int n;
int vis[200001];

vector <int> adj[200001];

int maxv = INF;

int dis[200001];

void dfs(int cur, int len){

    dis[cur] = len;
    
    for(int j: adj[cur]){
        
        if(vis[j] == 1){
            if(-dis[j] + dis[cur] +1< maxv){
                maxv = dis[cur] - dis[j] + 1;
            }
        }else if(vis[j] == 0){
            vis[j] = 1;
            dfs(j, len + 1);
        }
    
    }

    vis[cur] = 2;
}

bool empty[200001];

int main(){
    scanf("%d", &n);
    
    for(int i = 1; i<=n; i++){
        int temp;
        scanf("%d", &temp);
        adj[i].push_back(temp);
        empty[temp] = true;
    }
    for(int i = 1; i<=n; i++){
        if(!vis[i]) dfs(i, 0);
    }

    
    printf("%d", maxv);
    
    
}