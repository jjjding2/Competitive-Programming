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

char grid[100][100];

queue <pairs> monkey;
queue <pairs> Q;

int d[4][2] = {{0, 1}, {0, -1},{1, 0},{-1, 0}};

bool vis[100][100];


int main(){
    int x, y;
    scanf("%d %d", &x, &y);
    pairs insert;
    for(int i = 0; i<x; i++){
        string temp;
        cin >> temp;
        for(int z = 0; z<y; z++) {
            grid[i][z] = temp[z];
            if(grid[i][z] == 'M'){
                insert.first = i;
                insert.second = z;
                monkey.push(insert);
            }
        }
    }
    int count = 0;
    while(!monkey.empty()){
        pairs temp = monkey.front(); monkey.pop();
        if(!vis[temp.first][temp.second]){
            count ++;
            Q.push(temp);
            while(!Q.empty()){
                temp = Q.front(); Q.pop();
                for(int i = 0; i<4; i++){
                    int curx = temp.first +d[i][0];
                    int cury = temp.second + d[i][1];
                    if(curx <= x && cury <= y && curx >= 0 && cury >= 0 && !vis[curx][cury]){
                        if(grid[curx][cury] != '#'){
                            insert.first = curx;
                            insert.second = cury;
                            Q.push(insert);
                            vis[curx][cury] = true;
                        }
                    }
                }
            }
        }
    }
    cout << count;
}