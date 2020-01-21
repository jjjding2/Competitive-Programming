#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> plu;


ll arr[4][4];

bool empty[4][4];

int e = 0;
queue <pii> q;

void print(){
    for(int i = 0; i<3; i++){
        for(int z = 0; z<3; z++){
            cout << arr[i][z] << " ";
        }
        cout << "\n";
    }
}

void solve(){
    for(int i = 0; i<3; i++){
        if(empty[i][1] &&!empty[i][0] && !empty[i][2]){
            q.push({i, 1});
            empty[i][1] = false;
            e--;

            arr[i][1] = (arr[i][0] + arr[i][2])/2;
        }
    }
    for(int i = 0; i<3; i++){
        if(empty[1][i] &&!empty[0][i] && !empty[2][i]){
            q.push({1, i});
            empty[1][i] = false;
            e--;

            arr[1][i] = (arr[0][i] + arr[2][i])/2;
        }
    }
    
    for(int i = 0; i<3; i++){
                if(empty[i][2] && !empty[i][(0)] && !empty[i][1]){
                    q.push({i, 2});
                    empty[i][2] = false;
                    e--;

                    arr[i][2] = 2*arr[i][1] - arr[i][0];
                }
                if(empty[i][0] && !empty[i][1] && !empty[i][2]){
                    q.push({i, 0});
                    empty[i][0] = false;
                    e--;

                    arr[i][0] = 2*arr[i][1] - arr[i][2];
                }
        
        }
    
    for(int i = 0; i<3; i++){
        if(empty[2][i] && !empty[(0)][i] && !empty[1][i]){
            empty[2][i] = false;
            q.push({2, i});
            e--;
            
            arr[2][i] = 2*arr[1][i] - arr[0][i];
        }
        if(empty[0][i] && !empty[1][i] && !empty[2][i]){
            empty[0][i] = false;
            q.push({0, i});
            e--;
            
            arr[0][i] = 2*arr[1][i] - arr[2][i];
        }
        
    }

}


int main(){
    for(int i = 0; i<3; i++){
        for(int z = 0; z<3; z++){
            string temp;
            cin >> temp;
            if(temp[0] == 'X'){
                empty[i][z] = true;
                e ++;
            }else{
                int num = 1;
                q.push({i, z});
                bool neg = false;
                if(temp[0] == '-'){
                    neg = true;
                    for(int x = (int)temp.length() - 1; x>=1; x--){
                        arr[i][z] += num*(temp[x] - '0');
                        num = num * 10;
                    }
                }else{
                for(int x = (int)temp.length() - 1; x>=0; x--){
                    arr[i][z] += num*(temp[x] - '0');
                    num = num * 10;
                }
                }
                if(neg){
                    arr[i][z] = arr[i][z]*-1;
                }
            }
            
        }
    }

    if(e <= 3){
        
    while(e != 0){
        solve();
    }
    print();
        
    }else{
        solve();
        while(!q.empty()){
            int newx, newy;
            pii temp = q.front(); q.pop();
            
            newx = 1;
            newy = 1;
            if(empty[newx][temp.second]){
                empty[newx][temp.second] = false;
                arr[newx][temp.second] = 4;
            }
            solve();
            
            if(empty[temp.first][newy]){
                empty[temp.first][newy] = false;
                arr[temp.first][newy] = 4;
            }
            solve();
            
            if(empty[newx][newy]){
                empty[newx][newy] = false;
                arr[newx][newy] = 4;
            }
            solve();
            
        }
        if(empty[0][0]){
            empty[0][0] = false;
            arr[0][0] = 4;
        }
        solve();
        
        if(empty[0][2]){
            empty[0][2] = false;
            arr[0][2] = 4;
        }
        solve();
        
        if(empty[0][2]){
            empty[0][2] = false;
            arr[0][2] = 4;
        }
        solve();
        if(empty[2][2]){
            empty[2][2] = false;
            arr[2][2] = 4;
        }
        solve();
        print();
    }
    
    
    
}