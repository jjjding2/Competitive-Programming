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

vector <int> adj[1000];


queue <int> Q;

bool vis[1000][1000];
int dis[1000];

int freq[1000];

int in[1000];
int out[1000];

int choose2(int n){
    int val = 1;
    int val2= 1;
    for(int i = 1; i<=n; i++){
        val = val * i;
        if(i == n-2){
            val2 = val;
        }
    }
    return val/(2*val2);
    
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        string x;
        cin >> x;
        
        for(int z = 0; z<N; z++){
            if(x[z]!='0'){
                adj[i].push_back(z);
                in[z] ++;
                out[i] ++;
            }
        }
    }
    ll sum = 0;
    for(int i = 0; i<N; i++){
        Q.push(i);
        memset(dis, 0, sizeof(dis));
        while(!Q.empty()){
            int temp = Q.front(); Q.pop();
            for(int j: adj[temp]){
                if(dis[j] == 0 || dis[temp] + 1 < dis[j]){
                    dis[j] = dis[temp] + 1;
                    vis[i][j] = true;
                    vis[j][i] = true;
                    Q.push(j);
                }
            }
        }
    }
    for(int i = 0; i<N; i++){
        for(int z = 0; z<N; z++){
            if(!vis[i][z] && i!=z){
                vis[z][i] = true;
                sum ++;
            }
        }
    }
    cout << sum << "\n";
    
}