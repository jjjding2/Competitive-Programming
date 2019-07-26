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


vector <int> adj[100];
queue <ll> Q;

ll dis1[100];
ll dis2[100];
ll dis3[100];

bool vis[100];

int node1;
int node2;
int BFS(int start){
    ll max = 0;
    int maxi = 0;
    Q.push(start);
    vis[start] = true;

    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                vis[j] = true;
                dis1[j] = dis1[temp] + 1;
                if(dis1[j]>max){
                    max = dis1[j];
                    maxi = j;
                }
                Q.push(j);
            }
        }
    }
    return maxi;
}
int BFS2(int start){
    ll max = 0;
    int maxi = 0;
    Q.push(start);
    vis[start] = true;
    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                vis[j] = true;
                dis2[j] = dis2[temp] + 1;
                if(dis2[j]>max){
                    max = dis2[j];
                    maxi = j;
                }
                Q.push(j);
            }
        }
    }
    return maxi;
}

int BFS3(int start){
    ll max = 0;
    int maxi = 0;
    Q.push(start);
    vis[start] = true;

    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                vis[j] = true;
                dis3[j] = dis3[temp] + 1;
                if(dis3[j]>max){
                    max = dis3[j];
                    maxi =j;
                }
                Q.push(j);
            }
        }
    }
    return maxi;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N-1; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);
    }
    node1 = BFS(1);
    memset(vis, false, N+5);
    node2 = BFS2(node1);
    memset(vis, false, N+5);
    BFS3(node2);
    for(int i = 1; i<=N; i++){
        ll ff= max(dis2[i], dis3[i]) + 1;
        printf("%lld \n", ff);
    }
    }