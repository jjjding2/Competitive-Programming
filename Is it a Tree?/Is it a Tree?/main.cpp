#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;
int arr[4][4];
bool val[4];
bool vis[4];
queue <int> Q;
vector <int> adj[4];

void dfs(int cur, int pre){
    vis[cur] = true;
    for(int v: adj[cur]){
        if(v == pre){
            continue;
        }else if(!vis[v]){
            dfs(v, cur);
        }else{
            cout << "No";
            exit(0);
        }
    }
}

int main(){
    
    for(int i = 0; i<4; i++){
        for(int y = 0; y<4; y++){
            int temp;
            scanf("%d", &temp);
            arr[i][y] = temp;
            val[i] = true;
            val[y] = true;
            if(temp == 1){
                adj[y].push_back(i);
            }
        }
    }
    int cur = 0;
    for(int i = 0; i<4; i++){
        if(val[i]==true){
            cur = i;
        }
    }
    dfs(cur, -1);
    cout << "Yes";
}