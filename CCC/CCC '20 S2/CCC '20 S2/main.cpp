#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;

int arr[1005][1005];
bool vis[1005][1005];
queue <pii> q;

vector <pii> adj[1000001];

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++){
        for(int z = 1; z<=m; z++){
            cin >> arr[i][z];
            adj[i*z].push_back({i, z});
        }
    }
    q.push({1, 1});
    vis[1][1] = true;
    bool good = false;
    while(!q.empty()){
        pii temp = q.front(); q.pop();
        
        for(pii j: adj[ arr[temp.first][temp.second] ]){
            if(j.first >= 1 && j.first <= n && j.second >= 1 && j.second <=m){
                if(!vis[j.first][j.second]){
                    vis[j.first][j.second] = true;
                    q.push({j.first, j.second});
                    if(j.first == n && j.second == m){
                        good = true;
                    }
                }
            }
        }
    }
    if(good){
        cout << "yes";
    }else{
        cout << "no";
    }
    cout << "\n";
    
}
