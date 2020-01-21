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

int adj[100000];
queue <int> Q;
int connection [10001];
bool vis[100000];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1] = x2;
    }
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    while(x1!=0 && x2!=0){
        int val = 0;
        int val2 = 0;
            Q.push(x1);
            vis[x1] = true;
            while(!Q.empty()){
                int temp = Q.front(); Q.pop();
                int j = adj[temp];
                if(!vis[j] && j!=0){
                    connection[j] = connection[temp]+1;
                    vis[j] = true;
                    Q.push(j);
                }
                
            }
            val = connection[x2];
            memset(vis, false, sizeof(vis));
        memset(connection, 0, sizeof(connection));

        Q.push(x2);
        vis[x2] = true;
        while(!Q.empty()){
            int temp = Q.front(); Q.pop();
            int j = adj[temp];
            if(!vis[j] && j!=0){
                connection[j] = connection[temp]+1;
                vis[j] = true;
                Q.push(j);
            }
            
        }
        val2 = connection[x1];
        memset(vis, false, sizeof(vis));
        memset(connection, 0, sizeof(connection));
        
        if(val > 0 && val2>0){
            cout << "Yes " << val-1 << "\n";
        }else{
            cout << "No" << "\n";
        }
        scanf("%d %d", &x1, &x2);

    }
}