#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

queue <int> Q;
queue <int> gifts;
vector <int> adj[1000000];
bool gift [1000000];
int dis1 [1000000];
int dis2 [1000000];

bool vis1[1000000];
bool vis2[1000000];

int main(){
    int N; //build
    int M; //road
    int K; //gift
    int A; //s
    int B; //e
    scanf("%d %d %d %d %d", &N, &M, &K, &A, &B);
    for(int i = 0; i<K; i++){
        int temp;
        scanf("%d", &temp);
        gifts.push(temp);
    }
    for(int i = 0; i<M; i++){
        int x1;
        int x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);
    }
    
    Q.push(B);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int j: adj[cur]){
            if(!vis1[j]){
                vis1[j] = true;
                Q.push(j);
                dis1[j] = dis1[cur] + 1;
            }
        }
    }
    
    Q.push(A);
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int j: adj[cur]){
            if(!vis2[j]){
                vis2[j] = true;
                Q.push(j);
                dis2[j] = dis2[cur] + 1;
            }
        }
    }
    
    int maxv = 2147483647;
    while(!gifts.empty()){
        int temp = gifts.front(); gifts.pop();
        int newval = dis1[temp] + dis2[temp];
        if(newval < maxv){
            maxv = newval;
        }
    }
    cout << maxv;
    
    
    
    
    
    
}