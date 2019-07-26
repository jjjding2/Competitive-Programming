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

int par[1000000];

int rank[1000000];

struct E{int u, v, w;}e[1000000];

int mst = 0;

int find(int num){
    if(par[num] == num){
        return num;
    }else{
        par[num] = find(par[num]);
        return (par[num]);
    }
}

vector <int> adj[1000000];
int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 1; i<=N-1; i++){
        int a;
        scanf("%d", &a);
        adj[i].push_back(a);
        adj[a].push_back(i);
        if(i%K == 0){
            adj[i - K].push_back(i);
            adj[i].push_back(i - K);
        }
    }
    
    
}