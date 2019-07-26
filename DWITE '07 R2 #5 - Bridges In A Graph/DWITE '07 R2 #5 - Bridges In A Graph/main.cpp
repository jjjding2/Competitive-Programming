#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

vector <int> adj[10000];
queue <int> Q;
bool vis [10000];

int main(){
    for(int x = 0; x<5; x++){
        int N;
        int M;
        scanf("%d %d", &N, &M);
        for(int i = 0; i<M; i++){
            int x1, x2;
            scanf("%d %d", &x1, &x2);
            adj[x1].push_back(x2);
            adj[x2].push_back(x1);
        }
        int bridge = 0;
        for(int i = 1; i<=N; i++){
            for(int z = 0; z<adj[i].size(); z++){
                int temp = adj[i].front();
                adj[i].erase(adj[i].begin());
                int count = 1;
                Q.push(1);
                vis[1] = true;
                while(!Q.empty()){
                    int cur = Q.front(); Q.pop();
                    for(int j: adj[cur]){
                        if(!vis[j]){
                            vis[j] = true;
                            count ++;
                            Q.push(j);
                        }
                    }
                }
                memset(vis, false, sizeof(vis));
                if(count != N){
                    bridge ++;
                }
                adj[i].push_back(temp);
            }
        }
        cout << bridge << endl;
        for(int j = 0; j<=N; j++){
            adj[j].clear();
        }
    }
}