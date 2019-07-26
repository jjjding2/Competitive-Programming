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

int arr [1500][1500];
queue <pairs> Q;
bool vis[1500][1500];
int dir[4][4] =  {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main(){
    
    int N, H;
    scanf("%d %d", &N, &H);
    for(int i = 1; i<=N; i++){
        for(int x = 1; x<=N; x++){
            int temp;
            scanf("%d", &temp);
            arr[i][x] = temp;
        }
    }
    Q.push(pairs(1, 1));
    vis[1][1] = true;
    while(!Q.empty()){
        pairs cur = Q.front();
        Q.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0; i<4; i++){
            int newx = curx + dir[i][0];
            int newy = cury + dir[i][1];
            if(newx > 0 && newy > 0 && newx <=N && newy <=N&& abs(arr[newx][newy] - arr[curx][cury])<=H && !vis[newx][newy]){
                Q.push(pairs(newx, newy));
                vis[newx][newy] = true;
            }
        }
    }
    if(vis[N][N]){
        cout << "yes";
    }else{
        cout << "no";
    }
}