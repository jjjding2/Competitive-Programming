#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

ll d[4][4]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll sum [100][100];
bool vis [100][100];
bool spot[100][100];
ll stand;
ll N, M, K;


void yay(ll x, ll y){
    for(int z = 0; z<4; z++){
        ll newx = x + d[z][0];
        ll newy = y + d[z][1];
        if(newx <= N && newx > 0 && newy <= M && newy > 0){
            sum[newx][newy] += 1;
            
            if(sum[newx][newy] == 2 && !vis[newx][newy]){
                vis[newx][newy] = true;

                stand +=1;
                yay(x + d[z][0], y + d[z][1]);
            }
        }

    }
}

int main(){
    scanf("%lld %lld %lld", &N, &M, &K);
    stand = K;
    for(int i = 1; i<=K; i++){
        ll x1;
        ll y1;
        scanf("%lld %lld", &x1, &y1);
        vis[x1][y1] = true;
        for(int z = 0; z<4; z++){
            
            ll newx = x1 + d[z][0];
            ll newy = y1 + d[z][1];
            if(newx <= N && newx > 0 && newy <=M && newy > 0){
                sum[newx][newy] += 1;
                
                if(sum[newx][newy] == 2 && !vis[newx][newy]){
                    vis[newx][newy] = true;
                    stand ++;
                    yay(x1 + d[z][0], y1 + d[z][1]);
                    
                }
            }
        }

    }
    cout << stand;
    
}