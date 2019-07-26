#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

vector<int>adj[200000];
bool vis[20001];
queue<int> Q;

int main(){
    int N, M, A, B;
    scanf("%d %d %d %d", &N, &M, &A, &B);
    for(int i =0 ;i<M; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        adj[t1].push_back(t2);
        adj[t2].push_back(t1);
    }
    Q.push(A);
    vis[A] = true;
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        for(int i: adj[x]){
            if(!vis[i]){
                vis[i] = true;
                Q.push(i);
            }
        }
    }
    if(!vis[B]){
        cout << "NO SHAHIR!";
    }else{
        cout << "GO SHAHIR!";
    }
    
}