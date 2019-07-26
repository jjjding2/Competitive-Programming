#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define MM 100001
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

pii coord[100001];

ll dis[MM], q; bool vis[MM];
int N;

int dist(pii a, pii b){
    return max(abs(a.first - b.first), abs(a.second - b.second));
    
}

void dijkstra(int start){
    memset(dis, 0x3f, sizeof(dis)); dis[start]=0;
    for(int i=1; i<=N; i++){
        ll mi = dis[0]; int id=-1;
        for(int j=1; j<=N; j++)
            if(!vis[j] && dis[j] < mi) { mi=dis[j]; id=j; }
        if(id == -1) break;
        vis[id] = 1;
        for(int j=1; j<=N; j++){
            ll t2 = dis[id];
            if(dist(coord[i], coord[j]) < t2){
                t2 = dist(coord[i], coord[j]);
            }
            if(!vis[j]) dis[j] = min(dis[j], t2);
        }
    }
}

void solve(int start){
    memset(dis, 0x3f, sizeof(dis));
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA32.txt","r",stdin);
    
    for(int t = 0; t<10; t++){
        
        scanf("%d", &N);
        for(int i = 1; i<=N; i++){
            scanf("%d%d", &coord[i].first, &coord[i].second);
        }
        ll ans = INF;

            int i = 1;
                for(int z = i+1; z<=N; z++){
                    
                    if(dist(coord[i], coord[z]) < ans && dist(coord[i], coord[z]) != 0){
                        ans = dist(coord[i], coord[z]);
                    }
                }
            if(t == 1){
                ans = ans * 2;
            }
        
        cout << ans << "\n";
        
        
    }
    
    
}

