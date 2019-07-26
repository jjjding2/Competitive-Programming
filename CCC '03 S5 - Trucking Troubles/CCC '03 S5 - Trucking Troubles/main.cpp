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

vector <pii> adj[100000];

queue <int> Q;

int dis[100000];

int main(){
    int n, m, d;
    scanf("%d%d%d", &n,&m,&d);
    for(int i = 0; i<m; i++){
        int a, b,w;
        scanf("%d%d%d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    Q.push(1);
    dis[1] = MOD;
    while(!Q.empty()){
        int temp= Q.front(); Q.pop();
        for(pii j: adj[temp]){
            if(dis[j.first] == 0){
                dis[j.first] = j.second;
                Q.push(j.first);
            }
            else if((dis[j.first] < min(j.second, dis[temp]))){
                dis[j.first] = min(j.second, dis[temp]);
                Q.push(j.first);
            }
        }
    }
    int min = MOD;
    for(int i = 0; i<d; i++){
        int x;
        scanf("%d", &x);
        if(dis[x]<min){
            min = dis[x];
        }
    }
    printf("%d", min);
}