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

vector<int> adj[100000];
queue <int> Q;
bool vis[100000];
int dis[100000];
int main(){
    int N, M, A, B;
    scanf("%d %d %d %d", &N, &M, &A, &B);
    for(int i = 0; i<M; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);

    }
    int sum = 0;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                Q.push(j);
                vis[j] = true;
                dis[j] = dis[temp] + 1;
            }
        }
    }
    sum += dis[A];
    if(!vis[A]){
        cout << -1;
        return 0;
    }
    memset(vis, false, sizeof(vis));
    memset(dis, 0, sizeof(dis));

    Q.push(A);
    vis[A] = true;
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                Q.push(j);
                vis[j] = true;
                dis[j] = dis[temp] + 1;
            }
        }
    }
    
    sum += dis[B];
    if(!vis[B]){
        cout << -1;
        return 0;
    }
    cout << sum;
}