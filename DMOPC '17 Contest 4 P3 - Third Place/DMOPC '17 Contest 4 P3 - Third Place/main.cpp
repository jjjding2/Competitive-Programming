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

vector <pairs> adj[1001];
queue <ll> Q;
ll dis[100];
bool vis[100];
int main(){
    ll N;
    scanf("%lld", &N);
    ll rand = 1;
    for(int i = 0; i<N-1; i++){
        ll a, b, c;
        rand = a;
        scanf("%lld %lld %lld", &a, &b, &c);
        pairs temp;
        temp.first = b;
        temp.second = c;
        adj[a].push_back(temp);
        temp.first = a;
        adj[b].push_back(temp);
    }
    Q.push(rand);
    vis[rand] = true;
    ll maxv = 0;
    ll maxi = rand;
    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(pairs j: adj[temp]){
            if(!vis[j.first]){
                Q.push(j.first);
                vis[j.first] = true;
                dis[j.first] = dis[temp] + j.second;
                if(dis[j.first]>maxv){
                    maxv = dis[j.first];
                    maxi = j.first;
                }
            }
        }
    }
    memset(dis, 0, sizeof(dis));
    memset(vis, false, sizeof(vis));

    Q.push(maxi);
    vis[maxi] = true;
    ll maxv2 = 0;
    ll maxi2 = 0;
    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(pairs j: adj[temp]){
            if(!vis[j.first]  || dis[j.first] > dis[temp] + j.second){
                vis[j.first] = true;

                Q.push(j.first);
                dis[j.first] = dis[temp] + j.second;
                if(dis[j.first]>maxv2){
                    maxv2 = dis[j.first];
                    maxi2 = j.first;
                }
            }
        }
    }
    memset(dis, 0, sizeof(dis));
    memset(vis, false, sizeof(vis));
    ll truemax = 0;
    for(int i = 0; i<2; i++){
        ll maxv3 = 0;
        ll maxi3 = 0;
        for(int z = 1; z<N; z++){
            if(!adj[z].empty()){
                if(z!=maxi && z!=maxi2){
                    Q.push(z);
                    maxi3 = z;
                    break;
                }
            }
        }
        vis[maxi] = true;
        vis[maxi3] = true;
        

        while(!Q.empty()){
            ll temp = Q.front(); Q.pop();
            for(pairs j: adj[temp]){
                if(!vis[j.first] || dis[j.first] > dis[temp] + j.second){
                    Q.push(j.first);
                    vis[j.first] = true;
                    dis[j.first] = dis[temp] + j.second;
                    if(dis[j.first]>maxv3){
                        maxv3 = dis[j.first];
                        maxi3 = j.first;
                    }
                }
            }
        }
        
        Q.push(maxi3);
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        vis[maxi] = true;
        vis[maxi3] = true;
        maxv3 = 0;
        while(!Q.empty()){
            ll temp = Q.front(); Q.pop();
            for(pairs j: adj[temp]){
                if(!vis[j.first] || dis[j.first] > dis[temp] + j.second){
                    Q.push(j.first);
                    vis[j.first] = true;
                    dis[j.first] = dis[temp] + j.second;
                    if(dis[j.first]>maxv3){
                        maxv3 = dis[j.first];
                    }
                }
            }
        }
        if(maxv3 > truemax){
            truemax = maxv3;
        }
        memset(dis, 0, sizeof(dis));
        memset(vis, false, sizeof(vis));
        maxi = maxi2;
    }
    cout << truemax;
}