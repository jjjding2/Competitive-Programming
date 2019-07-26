#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <int> adj[7];

bool lone[7];

queue <int> Q;

int dis[7];
bool vis[7];
int arr[7];

int main(){
    int N;
    cin >> N;
    for(int i = 1; i<N; i++){
        int a;
        cin >> a;
        arr[i] = a;
        adj[a].push_back(i);
        lone[a] = true;
    }
    lone[N] = true;
    for(int i = 1; i<N; i++){
        if(!lone[i]){
            Q.push(i);
        }
    }
    int i = 0;
    while(!Q.empty()){
         i = Q.front(); Q.pop();
        if(!vis[i]){
            bool work = true;
            for(int j: adj[i]){
                if(!vis[j]){
                    Q.push(i);
                    work = false;
                    break;
                }
            }
            if(work){
                vis[i] = true;
                if(i!= N){
                    Q.push(arr[i]);
                }
                int include = 1;
                if(adj[i].size() == 0){
                    dis[i] = 1;
                }else if(adj[i].size() == 1){
                    dis[i] = dis[adj[i].front()]+1;
                }else{
                    int count = 0;
                    for(int j:adj[i]){
                        include = include*(dis[j] + 1);
                        count ++;
                    }
                    dis[i] += include;
                    
                }
            }
        }
        
    }
    
    
    cout << dis[N] ;
}