#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

class pairs{
public:
    int first;
    int second;
    pairs(){}
    pairs(int f, int s){
        first = f;
        second = s;
    }
};

char arr[1001][1001];
queue <pairs> Q;
bool vis[1001][1001];
int dis[1001][1001];
int dir[4][4] = {{1, 0}, {-1, 0},{0, 1},{0, -1}};

int newx, newy;

int main(){
    int L;
    scanf("%d", &L);
    for(int z = 0; z<L; z++){
        int x;
        int y;
        scanf("%d %d", &x, &y);
        for(int i = 0; i<x; i++){
            for(int a = 0; a<y; a++){
                cin >> arr[i][a];
            }
        }
        Q.push(pairs(0, 0));
        vis[0][0] = true;
        dis[0][0] = 1;
        while(!Q.empty()){
            pairs temp = Q.front(); Q.pop();
            int curx = temp.first;
            int cury = temp.second;
            if(arr[curx][cury] == '+'){
                for(int i = 0; i<4; i++){
                    newx = curx + dir[i][0];
                    newy = cury + dir[i][1];
                    if(!vis[newx][newy] && arr[newx][newy]!='*' && newx >= 0 && newy >=0){
                        dis[newx][newy] = dis[curx][cury] +1;
                        vis[newx][newy] = true;
                        Q.push(pairs(newx, newy));
                    }
                }
            }
            else if(arr[curx][cury] == '-'){
                for(int i = 2; i<4; i++){
                    newx = curx + dir[i][0];
                    newy = cury + dir[i][1];
                    if(!vis[newx][newy]&& arr[newx][newy]!='*' && newx >= 0 && newy >=0){
                        dis[newx][newy] = dis[curx][cury] +1;

                        vis[newx][newy] = true;
                        Q.push(pairs(newx, newy));
                    }
                }
            }
            else if(arr[curx][cury] == '|'){
                for(int i = 0; i<2; i++){
                    newx = curx + dir[i][0];
                    newy = cury + dir[i][1];
                    if(!vis[newx][newy]&& arr[newx][newy]!='*'&& arr[newx][newy]&& newx >= 0 && newy >=0){
                        dis[newx][newy] = dis[curx][cury] +1;

                        vis[newx][newy] = true;
                        Q.push(pairs(newx, newy));
                    }
                }
            }

        }
        if(dis[x-1][y-1]==0){
            cout << "-1" << endl;
        }else{
            cout << dis[x-1][y-1] << endl;
        }
        for(int i = 0; i<30; i++){
            for(int a = 0; a<30; a++){
                vis[i][a] = false;
                arr[i][a] = '\0';
                dis[i][a] = 0;
            }
        }
    }
}