#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pairs;
pairs start, fin; queue<pairs> Q; bool vis[9][9]; int dis [9][9];
int dir[8][2] ={{1, 2},{2, 1},{2, -1},{1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int main(){
    cin >> start.first >>  start.second >> fin.first >> fin.second;
    Q.push(start);
    dis[Q.front().first][Q.front().second] = 0;
    vis[Q.front().first][Q.front().second] = true;
    while(!Q.empty()){
        int curx = Q.front().first;
        int cury = Q.front().second;
        Q.pop();
        int tempx, tempy;
        for(int i = 0; i<8; i++){
            tempx = curx + dir[i][0];
            tempy = cury + dir[i][1];
            if(tempx < 9 && tempx >0 && tempy <9 && tempy >0){
            if(!vis[tempx][tempy] || dis[curx][cury]+1 < dis[tempx][tempy]){
                dis[tempx][tempy] = dis[curx][cury] + 1;
                vis[tempx][tempy] = true;
                
                Q.push(pairs(tempx, tempy));
            }
            }
            
        }
    
    }
    cout << dis[fin.first][fin.second];
    
}