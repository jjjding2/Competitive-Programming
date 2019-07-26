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

vector <pii> adj[20001];
vector <pii> adj2[20001];


int hubd[201][20001];

int back[201][20001];

priority_queue<pii, vector <pii>, greater <pii>>q;

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N, M, K, Q;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    
    for(int i = 0; i<M; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].push_back({b, c});
        adj2[b].push_back({a, c});
        
    }
    memset(hubd, INF, sizeof(hubd));
    memset(back, INF, sizeof(back));
    for(int i = 0; i<K; i++){
        int a;
        scanf("%d", &a);
        hubd[i][a] = 0;
        q.push({0, a});
        while(!q.empty()){
            pii temp = q.top(); q.pop();
            if(hubd[i][temp.second] < temp.first){
                continue;
            }
            for(pii j: adj[temp.second]){
                if(j.first == a){
                    continue;
                }
                if((hubd[i][j.first] > hubd[i][temp.second] + j.second) ){
                    hubd[i][j.first] = hubd[i][temp.second] + j.second;
                    q.push({hubd[i][j.first], j.first});
                }
                
            }
            
        }
        q.push({0, a});
        back[i][a] = 0;

        while(!q.empty()){
            pii temp = q.top(); q.pop();
            if(back[i][temp.second] < temp.first){
                continue;
            }
            for(pii j: adj2[temp.second]){
                if(j.first == a){
                    continue;
                }
                if((back[i][j.first] > back[i][temp.second] + j.second) ){
                    back[i][j.first] = back[i][temp.second] + j.second;
                    q.push({back[i][j.first], j.first});
                }
                
            }
            
        }

    }

    int work = 0;
    int tot = 0;
    for(int i = 0; i<Q; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        bool good = false;
        int minv = INF;
        for(int i = 0; i<K; i++){
            if(hubd[i][b]!=INF && back[i][a]!=INF && hubd[i][b] + back[i][a] < minv){
                good = true;
                minv = hubd[i][b] + back[i][a];
            }
        }
        if(good){
            work ++;
            tot += minv;
        }
                                        
    }
    printf("%d", work);
    printf("\n");
    printf("%d", tot);
    
    
    
    
}