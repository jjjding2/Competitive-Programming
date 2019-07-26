#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

vector <int> adj[10001];
int dis[1001][1001];
bool vis[1001];
queue <int> Q;
int main(){
    int N, M, T;
    scanf("%d %d %d", &N, &M, &T);
    for(int i = 0; i<M; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
    }
    for(int i = 0; i<=N; i++){
        Q.push(i);
        while(!Q.empty()){
            int temp = Q.front(); Q.pop();
            for(int j: adj[temp]){
                if(dis[i][j] == 0 || dis[i][j]>dis[i][temp] + 1){
                    dis[i][j] = dis[i][temp] + 1;
                    Q.push(j);
                }
            }
        }
        
    }
    int query;
    scanf("%d", &query);
    for(int i = 0; i<query; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        if(dis[x][y] == 0){
            cout << "Not enough hallways!"<< "\n";
        }else{
            cout << dis[x][y]*T << "\n";
        }
    }
}