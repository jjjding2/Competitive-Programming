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
typedef pair< ll, ll> pll;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct edge{ll dest; ll weight; ll index;};

vector <edge> adj[1000001];

ll A, B, C;

priority_queue <pll, vector <pll>, greater <pll>> q;

bool work(ll end){
    ll dis[1000001];
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    q.push({0, A});
    dis[A] = 0;
    while(!q.empty()){
        pll temp = q.top(); q.pop();
        
        if(temp.first > dis[temp.second]){
            continue;
        }
        for(edge j: adj[temp.second]){
            if(j.index <= end && dis[temp.second] + j.weight < dis[j.dest]){
                dis[j.dest] = dis[temp.second] + j.weight;
                q.push({dis[j.dest], j.dest});
            }
        }
    }
    if(dis[B]!=0x3f3f3f3f && dis[B] < C){
        return true;
    }else{
        return false;
    }
}

int main(){
    ll N, M;
    scanf("%lld%lld", &N, &M);
    for(int i = 1; i<=M; i++){
        ll a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        adj[a].push_back({b, c, i});
        adj[b].push_back({a, c, i});
    }
    scanf("%lld%lld%lld", &A, &B, &C);
    ll low = 1; ll high = M; ll middle = (low + high)/2;
    bool possible = false;
    ll lastwork = middle;
    while(low <= high){
        middle = (low + high)/2;
        if(work(middle)){
            high = middle - 1;
            lastwork = middle;
            possible = true;
        }else{
            low = middle + 1;
        }
    }
    if(possible){
        printf("%lld", lastwork);
    }else{
        printf("%d", -1);
    }
}