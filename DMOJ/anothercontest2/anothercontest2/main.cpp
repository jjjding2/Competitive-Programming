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

struct pairs{ ll first,second; };

ll path[103][103];

ll N;

bool vis[103];
ll dis[103];


vector <pairs> adj [103][103];

ll orig;

vector <ll> v;

vector <ll> v2 [103][103][103];
void dfs(ll cur, ll pre, ll max, ll dislast, vector <ll> v){
    for(int i = 1; i<=N; i++){
        if(path[cur][i] != 0 && i != pre && !(find(v.begin(), v.end(), i) != v.end())){
            vis[i] = true;
            dis[i] = dislast + 1;
            ll newmax = max;
            if(path[cur][i] > max){
                newmax = path[cur][i];
            }
            pairs temp;
            temp.first = dis[i];
            temp.second = newmax;
            adj[orig][i].push_back(temp);
            v.push_back(i);
            v2[dis[i]][newmax][adj[orig][i].size()].push_back(dis[i]);
            ll newlast = dis[i];
            dis[i] = 0;
            dfs(i, cur, newmax, newlast, v);
            v.pop_back();

        }
    }
}

int main(){
    scanf("%lld", &N);
    for(ll i = 1; i<=N; i++){
        for(ll y = 1; y<=N; y++){
            scanf("%lld", &path[i][y]);
        }
    }
        for(ll i = 1; i<=N; i++){
            orig = i;
            dfs(i, -1, 0, 0, v);
            memset(vis, false, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            
        }
    
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i<Q; i++){
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        ll minv = 9223372036854775807;
        for(int z = 0; z< adj[a][b].size(); z++){
            if(adj[a][b].at(z).second <= c && adj[a][b].at(z).first < minv){
                minv =adj[a][b].at(z).first;
            }else if(adj[a][b].at(z).second > c){
                int cursum = 0;
                int curmin = pow(2, 30)-1;
                int count = 0;
                for(int r = 0; r< min(minv, abs(adj[a][b].at(z).second-c)); r++){
                    for(int x = 0; x<v2[a][b][z-1].size(); x ++){
                        if(cursum + v2[a][b][z-1].at(x) <= r){
                            cursum += v2[a][b][z-1].at(x);
                        }else{
                            if(cursum > curmin){
                                curmin = cursum;
                            }
                            cursum = 0;
                            count ++;
                        }
                    }
                    if(count <= c){
                        if(curmin < minv){
                            minv = curmin;
                        }
                    }
                }
            }
            
        }
        if(minv == 9223372036854775807){
            cout << 0 << "\n";
        }else{
            cout << minv << "\n";
        }
    }
}