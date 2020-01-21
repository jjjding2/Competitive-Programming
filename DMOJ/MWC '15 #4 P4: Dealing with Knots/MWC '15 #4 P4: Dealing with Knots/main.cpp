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

bool vis[10000];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
    }
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    Q.push(x1);
    vis[x1] = true;
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(int j: adj[temp]){
            if(!vis[j]){
                Q.push(j);
                vis[j] = true;
            }
        }
    }
    cout << (vis[x2] ? "Tangled" : "Not Tangled");
}