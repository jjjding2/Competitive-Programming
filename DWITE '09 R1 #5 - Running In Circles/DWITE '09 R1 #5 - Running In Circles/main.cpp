#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;


int N;
vector <int> adj[10001];
bool vis[10000];
int maxv;
int cycles;
void dfs(int cur, int pre, int size, int arr1[1001]){
    vis[cur] = true;
    size ++;
    for(int v: adj[cur]){
        if(!vis[v]){
            arr1[size] = v;
            dfs(v, cur, size, arr1);
        }else{
            for(int i = 0; i<size; i++){
                if(v == arr1[i]){
                    maxv = size - i;
                }
            }
        }
    }
}

int main(){
    for(int i = 0; i<5; i++){
        scanf("%d", &N);
        int one, two;
        scanf("%d %d", &one, &two);

        adj[one].push_back(two);
        for(int z = 1; z<N; z++){
            int x1, x2;
            scanf("%d %d", &x1, &x2);
            adj[x1].push_back(x2);
        }
        
            vis[one] = true;
            cycles = 0;
            int arrr[1001];
            arrr[0] = one;
            dfs(one, -1, 0, arrr);
            for(int z = 0; z<=100; z++){
                vis[z] = false;
                adj[z].clear();
                arrr[z] = 0;
            }
        
        cout << maxv;
        cout << "\n";
    }
    
}