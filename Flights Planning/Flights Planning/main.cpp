#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <pii> adj[201];

int hubd[200][201];
bool hub[201];

queue <int> hubs;

priority_queue<pii, vector <pii>, greater <pii>>q;

int in[201];
int out[201];

int realv[201];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N, M, K, Q;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        in[a] = b; //keeps track of what each node is going into (regardless of whether it is a hub or not)
        out[b] = a;
    }
    for(int i = 0; i<K; i++){
        int temp;
        scanf("%d", &temp);
        hub[temp] = true; //is it a hub?
        realv[temp] = i; //smaller corresponding index to reduce memory
        hubs.push(temp); //holds the hub for later use
    }
    memset(hubd, INF, sizeof(hubd));
    while(!hubs.empty()){
        int a = hubs.front(); hubs.pop();
        int B = realv[a]; //this is used to update distances using smaller indices
        q.push({0, a});
        hubd[B][a] = 0;
        while(!q.empty()){
            pii temp = q.top(); q.pop();
            if(hubd[B][temp.second] < temp.first){
                continue;
            }
            for(pii j: adj[temp.second]){
                if((hubd[B][j.first] > hubd[B][temp.second] + j.second )){
                    hubd[B][j.first] = hubd[B][temp.second] + j.second;
                    q.push({hubd[B][j.first], j.first});
                }
                
            }
            
        }
        
    }
    int work = 0;
    int tot = 0;
    for(int i = 0; i<Q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        int dis = 0;
        int f = a;
        int s= b;
        if(!hub[a]){
            if(in[a]== 0){
                continue;
            }
            f = in[a];
            for(int z = 0; z<adj[a].size(); z++){
                if(adj[a][z].first == f){
                    dis += adj[a][z].second;
                    break;
                }
            }
        }
        if(!hub[b]){
            if(out[b] == 0){
                continue;
            }
            s = out[b];
            for(int z = 0; z<adj[s].size(); z++){
                if(adj[s][z].first == b){
                    dis += adj[s][z].second;
                    break;
                }
            }
        }
        if(hubd[f][s] == INF&& f != s){
            continue;
        }
        if(f != s){
            dis+= hubd[realv[f]][s];
        }
        work ++;
        tot += dis;
    }
    printf("%d", work);
    printf("\n");
    printf("%d", tot);
    
    
    
    
}