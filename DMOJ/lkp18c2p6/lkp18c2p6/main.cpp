#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef unsigned long long int ll;

typedef pair<ll, ll> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <pii> adj[100001];

vector <pii> adj2[100001];

bool wow[100001];

ll disc[100001];

ll maxd = 0;
ll maxi = 0;

ll E;

ll dis[100001];



void clear(ll cur, ll pre){
    for(pii j: adj[cur]){
        
        if(j.first != pre && (disc[j.first] > disc[cur] + j.second)){
            disc[j.first] = disc[cur] + j.second;
            clear(j.first, cur);
            
            if(disc[j.first] > maxd && wow[j.first] == true && disc[j.first] != INF){
                maxd = disc[j.first];
                maxi = j.first;
            }
            if(wow[j.first] || !adj2[j.first].empty()){
                adj2[j.first].push_back({cur, j.second});
                adj2[cur].push_back({j.first, j.second});
                E += j.second;
                
                
            }
        }
        
    }
    
}
priority_queue<pii, vector<pii>, greater<pii>>q;

queue <int> Q;
int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll N, M, K;
    scanf("%lld%lld%lld", &N, &M, &K);
    ll ree = 1;
    for(int i = 0; i<K; i++){
        scanf("%lld", &ree);
        wow[ree] = true;
    }
    
    for(int i = 0; i<N-1; i++){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
        
        
    }
    memset(disc, INF, sizeof(disc));
    disc[ree] = 0;
    clear(ree, -1);
    
    q.push({0, maxi});
    memset(dis, INF, sizeof(dis));
    
    dis[maxi]= 0;
    ll maxd2 = 0;
    
    while(!q.empty()){
        pii temp = q.top(); q.pop();
        if(temp.first > dis[temp.second]){
            continue;
        }
        for(pii j: adj2[temp.second]){
            if(dis[j.first] > dis[temp.second] + j.second){
                dis[j.first] = dis[temp.second] + j.second;
                q.push({dis[j.first], j.first});
                if(dis[j.first] > maxd2 && dis[j.first] != INF && wow[j.first] == true){
                    maxd2 = dis[j.first];
                }
            }
            
            
        }
        
    }
    printf("%llu", 2*(E - maxd2) + maxd2);
    
}