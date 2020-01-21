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

struct pairs{ int first,second; };


int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

char graph [1003][1003];
bool teleport[1003][1003];
queue <pairs> Q;

int dis[1003][1003];
bool vis[1003][1003];

int main(){

    int x, y;
    scanf("%d %d", &x, &y);
    int sx, sy, ex, ey;
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for(int i = 0; i<x; i++){
        string temp;
        cin >> temp;
        for(int z = 0; z<y; z++){
            graph[i][z] = temp[z];
        }
    }
    int T;
    scanf("%d", &T);
    for(int i = 0; i<T; i++){
        int tx, ty;
        scanf("%d %d", &tx, &ty);
        teleport[tx][ty] = true;
    }
    
    pairs insert;
    insert.first = sx;
    insert.second = sy;
    Q.push(insert);
    
    ll mind = pow(2, 64)-1;
    
    vis[sx][sy] = true;

     
        while(!Q.empty()){
            pairs temp = Q.front(); Q.pop();
            for(int i = 0; i<4; i++){
                int newx = temp.first + d[i][0];
                int newy = temp.second + d[i][1];
                if(newx <= x+1 && newy <= y+1 && newx >= 0 && newy >= 0){
                    if(dis[newx][newy] == 0 && !vis[newx][newy] && graph[newx][newy] != 'X'){
                        vis[newx][newy] = true;
                        dis[newx][newy] = dis[temp.first][temp.second] + 1;
                        if(teleport[newx][newy] && dis[newx][newy] < mind){
                            mind = dis[newx][newy];
                        }
                        insert.first = newx;
                        insert.second = newy;
                        Q.push(insert);
                    }
                    
                }
            }
        }
    if(teleport[sx][sy] == true){
        mind = 0;
    }
    if(abs(dis[ex][ey] - mind) > 0){
        cout << dis[ex][ey] - mind ;
    }else{
        cout << 0;
    }

}