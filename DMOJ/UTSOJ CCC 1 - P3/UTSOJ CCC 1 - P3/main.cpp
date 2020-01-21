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

vector <int> adj[100000];

bool vis[10001][10001];

queue <int> q;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M, Q;
    cin >> N >> M >> Q;
    for(int i = 0; i<M; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i<Q; i++){
        int bad;
        cin >> bad;
        for(int z = i; z<=Q; z++){
            vis[z][bad] = true;
        }
        q.push(1);
        if(vis[i][1] == true || vis[i][N]){
            printf("NO\n");
        }else{
            while(!q.empty()){
                int temp = q.front(); q.pop();
                for(int j: adj[temp]){
                    if(!vis[i][j]){
                        vis[i][j] = true;
                        q.push(j);
                    }
                }
            }
            if(vis[i][N] == true){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}