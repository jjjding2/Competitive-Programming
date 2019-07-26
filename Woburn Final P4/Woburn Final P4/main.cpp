#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;

int ans[101][101];

int r, c;

void print(){
    for(int x = 0; x<r; x++){
        for(int z = 0; z<c; z++){
            if(ans[x][z] == 0){
                cout << ".";
            }else if(ans[x][z] == 1){
                cout << "#";
            }else if(ans[x][z] == 2){
                cout << "S";
            }else if(ans[x][z] == 3){
                cout << "E";
            }
            
        }
        cout << "\n";
        
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0)
    scanf("%d%d", &r, &c);
    if(c == 2){
        ans[0][0] = 2;
        ans[0][1] = 3;
    }else if(c == 3){
        ans[r-1][0] = 2;
        ans[1][c-1] = 3;

        for(int i = 1; i < r - 1; i++){
            ans[i][1] = 1;
        }
    }else if(c == 4){
        
        ans[r-1][0] = 2;
        ans[2][c-1] = 3;
        int x1 = r - 2;
        int y1 = 1;
        for(int i = 1; i<c-1; i++){
            ans[x1][y1] = 1;
            x1 -= i;
            y1 += i;
            
        }
        
    }else if(c == 5){
        
        ans[r-1][0] = 2;
        ans[2][c-2] = 3;
        ans[1][c-2] = 1;
        int x1 = r - 2;
        int y1 = 1;
        for(int i = 1; i<min(c-1, r-1) && x1 != 0; i++){
            ans[x1][y1] = 1;
            x1 -= i;
            y1 += i;
            
        }
        
        
    }else{
        ans[r-1][0] = 2;
        int x1 = r - 2;
        int y1 = 1;
        for(int i = 1; i<min(c-1, r-1) && x1 >= 0 && y1 >= 0; i++){
            ans[x1][y1] = 1;
            x1 -= 1;
            y1 += 1;
        }
        ans[r-2][y1] = 3;
    }
    print();
}
