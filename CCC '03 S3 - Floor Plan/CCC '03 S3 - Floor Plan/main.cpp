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
    pairs(int s, int v){
        first = s;
        second = v;
    }
    
};

char arr[1000][1000];

bool vis[1000][1000];


queue <pairs> Q;

int dir[8][2] ={{1, 0},{-1, 0},{0, -1},{0, 1}};

int rooms[1000];

bool cmp(int A, int B){
    return (A>B);
}
int main(){
    int F;
    int Y;
    int X;
    scanf("%d %d %d", &F, &Y, &X);
    for(int x = 0; x<Y; x++){
        for(int y = 0; y<X; y++){
            char a;
            scanf(" %c",&a);
            arr[x][y] = a;
        }
    }
    int count = 0;
    
    for(int x = 0; x<Y; x++){
        for(int y = 0; y<X; y++){
            if(!vis[x][y] && arr[x][y] == '.'){
                vis[x][y] = true;
                Q.push(pairs(x, y));
                rooms[count] ++;
                while(!Q.empty()){
                    int startx =Q.front().first;
                    int starty = Q.front().second;
                    int curx, cury;
                    Q.pop();
                    for(int i = 0; i<4; i++){
                        curx = startx+  dir[i][0];
                        cury = starty + dir[i][1];
                        if(arr[curx][cury] == '.' && (!vis[curx][cury])){
                            vis[curx][cury] = true;
                            rooms[count] ++;
                            
                            Q.push(pairs(curx, cury));
                        }
                    }
                    
                }
                count ++;
                
            }
        }
    }
    /*
     for(int x = 0; x<X; x++){
     for(int y = 0; y<Y; y++){
     cout << dis[x][y] << " ";
     }
     cout << "\n";
     }
     
     for(int i = 0; i<count; i++){
     cout << rooms[i] << " ";
     }
     */
    
    sort(rooms, rooms + count, cmp);
    int clear = 0;
    int total = 0;
    for(int i = 0; i<count; i++){
        total = rooms[i] + total;
    }
    
    for(int i = 0; i<count; i++){
        if(F>=rooms[i] && rooms[i]!=0){
            F  = F - rooms[i];
            clear ++;
            total -= rooms[i];
        }else{
            break;
        }
    }
    if(clear == 1){
        cout << clear << " room, " << F << " square metre(s) left over";

    }else{
        cout << clear << " rooms, " << F << " square metre(s) left over";
    }
}
