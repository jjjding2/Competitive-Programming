#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

queue <int> Q;
queue <int> Q2;

vector <int> adj[1001];

int dis[1001];
int dis2[1001];

bool vis[1000];

priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int,int>>> q;

int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i<M; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int G;
    scanf("%d", &G);
    for(int i = 0; i<=N; i++){
        dis[i] = INT_MAX-10;
        dis2[i] = INT_MAX-10;
    }
    for(int i = 0; i<G; i++){
        int a;
        scanf("%d", &a);
        Q2.push(a);
        dis2[a] = 0;
    }
    Q.push(1);
    dis[1] = 0;
    
    while(!Q2.empty()){
        int temp = Q2.front(); Q2.pop();
        for(int j: adj[temp]){
            if(dis2[j] > dis2[temp] + 4){
                dis2[j] = dis2[temp]+4;
                Q2.push(j);
            }
        }
    }
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(int j:adj[temp]){
            if((dis[temp] + 1 <dis2[j]) && dis[j] > dis[temp]+1){
                dis[j] = dis[temp]+1;
                Q.push(j);
            }
        }
    }

    if((dis[N] < dis2[N])){
        printf("%d", dis[N]);
    }else{
        printf("sacrifice bobhob314");
    }
}