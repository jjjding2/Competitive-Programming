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


class node{
public:
    int next;
    int time;
    int hull;
    node(){}
    node(int n, int t, int h){
        next = n;
        time = t;
        hull = h;
    }
    
};

class pairs{
public:
    int next;
    int hull;
    pairs(){}
    pairs(int n, int h){
        next = n;
        hull = h;
    }
    
};

vector <node> adj[10000];
queue <pairs> Q;
int dis[10000][300];

int main(){
    int k, n, m;
    scanf("%d %d %d", &k, &n, &m);
    for(int i = 0; i<m; i++){
        int a, b, t, kk;
        scanf("%d %d %d %d", &a, &b, &t, &kk);
        adj[a].push_back(node(b, t, kk));
        adj[b].push_back(node(a, t, kk));
    }
    int start, end;
    scanf("%d %d", &start, &end);
    Q.push(pairs(start, 0));
    while(!Q.empty()){
        int temp = Q.front().next;
        int thic = Q.front().hull;
        Q.pop();
        for(node j: adj[temp]){
            if(thic + j.hull < k){
                if(dis[j.next][thic + j.hull] == 0 || dis[j.next][thic + j.hull] > dis[temp][thic] + j.time){
                    dis[j.next][thic + j.hull] = dis[temp][thic] + j.time;
                    Q.push(pairs(j.next, thic + j.hull));
                    
                }
            }
        }
    }
    int min = pow(2, 31)-1;
    for(int i = 0; i<k; i++){
        if(dis[end][i] < min && i < k && dis[end][i] != 0){
            min = dis[end][i];
        }
    }
    cout << (min == (pow(2, 31)-1) ? -1:min);
    
}