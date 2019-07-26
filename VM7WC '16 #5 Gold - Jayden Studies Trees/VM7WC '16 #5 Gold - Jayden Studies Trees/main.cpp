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

queue <int> Q;
vector <int> adj[10000];
int dis[100];
int dis2[100];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N-1; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);
    }
    
    Q.push(1);
    int maxd = 0;
    int index = 1;
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int j: adj[cur]){
            if(dis[j] == 0 || dis[j] > dis[cur] + 1){
                dis[j] = dis[cur] + 1;
                Q.push(j);
            }
            if(dis[j] > maxd){
                maxd = dis[j];
                index = j;
            }
        }
    }
    
    int maxd2 = 0;
    Q.push(index);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int j: adj[cur]){
            if(dis2[j] == 0|| dis2[j] > dis2[cur] + 1){
                dis2[j] = dis2[cur] + 1;
                Q.push(j);
            }
            if(dis2[j] > maxd2){
                maxd2 = dis2[j];
                index = j;
            }
        }
    }
    cout << maxd2;
}