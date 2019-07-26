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

bool pho[100001];

int dis[100001];
int dis2[100001];

vector <int> adj[100001];

vector <int> adj2[100001];

int maxd = 0;
int maxi = -1;

int E = 0;

void clear(int cur, int pre){
    
    for(int j: adj[cur]){
        if(j != pre && dis[j] > dis[cur] + 1){
            dis[j] = dis[cur] + 1; clear(j, cur);
            if(dis[j] > maxd && pho[j] == true){
                maxd = dis[j];
                maxi = j;
            }
            if(pho[j] || !adj2[j].empty()){
                adj2[j].push_back(cur);
                adj2[cur].push_back(j);
                E += 1;

            }
        }
    }
}

queue <int> q;
int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M;
    scanf("%d%d", &N, &M);
    int c = 0;
    for(int i = 0; i<M; i++){
        scanf("%d", &c);
        
        pho[c] = true;
    
    }
    for(int i = 0; i<N-1; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis, INF, sizeof(dis));
    dis[c] = 0;
    clear(c, -1);
    
    
    q.push(maxi);
    int maxd2 = 0;
    memset(dis2, INF, sizeof(dis2));
    dis2[maxi] = 0;
    while(!q.empty()){
        int temp = q.front(); q.pop();
        
        for(int j: adj2[temp]){
            if(dis2[j] > dis2[temp] + 1){
                dis2[j] = dis2[temp] + 1;
                q.push(j);

            }
        }
    
    }
    for(int j = 0; j<N; j++){
        if(dis2[j] > maxd2 && dis2[j] != INF){
            maxd2 = dis2[j];
        }
    }
    printf("%d", maxd2 + abs(2*(E - maxd2)));
    
}