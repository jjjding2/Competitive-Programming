#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int arr[51][51];
int ff[51];
queue <int> Q;
bool vis[51];
int dis[51];

int main(){
    arr[2][6] = 1;
    arr[6][2] = 1;
    arr[1][6] = 1;
    arr[6][1] = 1;
    arr[3][6] = 1;
    arr[6][3] = 1;
    arr[4][6] = 1;
    arr[6][4] = 1;
    arr[3][4] = 1;
    arr[4][3] = 1;
    arr[4][5] = 1;
    arr[5][4] = 1;
    arr[6][5] = 1;
    arr[5][6] = 1;
    arr[3][5] = 1;
    arr[5][3] = 1;
    arr[15][3] = 1;
    arr[3][15] = 1;
    arr[6][7] = 1;
    arr[7][6] = 1;
    arr[7][8] = 1;
    arr[8][7] = 1;
    arr[8][9] = 1;
    arr[9][8] = 1;
    arr[9][12] = 1;
    arr[12][9] = 1;
    arr[9][10] = 1;
    arr[10][9]=1;
    arr[12][11] = 1;
    arr[11][12] = 1;
    arr[11][10] = 1;
    arr[10][11] = 1;
    arr[15][13] = 1;
    arr[13][15] = 1;
    arr[12][13] = 1;
    arr[13][12] = 1;
    arr[14][13] = 1;
    arr[13][14] = 1;
    
    arr[16][18] = 1;
    arr[18][16] = 1;
    arr[16][17] = 1;
    arr[17][16] = 1;
    arr[18][17] = 1;
    arr[17][18] = 1;
    string input;
    cin >> input;
    while(input != "q"){
        if(input == "i"){
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x][y] = 1;
            arr[y][x] = 1;
        }
        else if(input == "d"){
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x][y] = 0;
            arr[y][x] = 0;
        }
        else if(input == "n"){
            int x;
            scanf("%d", &x);
            int count = 0;
            for(int i = 0; i<50; i++){
                if(arr[x][i]==1){
                    count += 1;
                }
            }
            cout << count << "\n";
        }
        else if(input == "f"){
            int x;
            scanf("%d", &x);
            int count = 0;
            
            for(int i = 0; i<50; i++){
                if(arr[x][i]==1){
                    for(int z = 0; z<50; z++){
                        if(arr[i][z] == 1 && arr[x][z]==0 && z!=x){
                            ff[z] = 1;
                        }
                    }

                }
            }
            for(int i = 0; i<50; i++){
                if(ff[i]==1){
                    count ++;
                    ff[i] = 0;
                }
            }
            cout << count << "\n";
        }
        else if(input == "s"){
            int x, y;
            scanf("%d %d", &x, &y);
            Q.push(x);
            vis[x] = true;
            
            while(!Q.empty()){
                int cur = Q.front(); Q.pop();
                for(int i = 0; i<50; i++){
                    if(arr[cur][i] == 1 && (dis[i] == 0 || dis[i]>dis[cur])){
                        dis[i] = dis[cur]+1;
                        Q.push(i);
                    }
                }
            }
            if(dis[y] == 0){
                cout << "Not connected" << "\n";
            }else{
                cout << dis[y] << "\n";
            }
            for(int i = 0; i<50; i++){
                dis[i] = 0;
            }
        }
        cin >> input;
    }
    
    
    
    
    
}