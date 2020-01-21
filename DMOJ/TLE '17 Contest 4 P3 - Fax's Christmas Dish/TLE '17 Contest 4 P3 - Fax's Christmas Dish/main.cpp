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

vector <int> adj[300001];

queue <int> q;

int need[300001];

int dis[300001];

int main(){
    int N, M, D;
    scanf("%d%d%d", &N, &M, &D);
    for(int i = 0; i<M; i++){
        int a, n;
        scanf("%d%d", &a, &n);
        for(int i =0; i<n; i++){
            int temp;
            scanf("%d", &temp);
            adj[a].push_back(temp);
        }
    }
    q.push(1);
    
    while(!q.empty()){
        int temp = q.fr

        for(int j: adj[q.front()])
    }
}