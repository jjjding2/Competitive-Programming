#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pii;
//{v, w}
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

char arr[101][101];

queue <pii> Q;

int d[8][2] = {{0, 1},{0, -1},{1, 0}, {-1, 0}, {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};

int main(){
    int x1, y1;
    scanf("%d%d", &x1, &y1);
    for(int x = 0; x<x1; x++){
        for(int y = 0; y<y1; y++){
            char temp;
            cin >> temp;
            arr[x][y] = temp;
            if(temp=='.'){
                Q.push({x, y});
            }
        }
    }
    int sum = 0;
    while(!Q.empty()){
        pii cur = Q.front(); Q.pop();
        int num = 8;
        int fail = 0;
        for(int i = 0; i<8; i++){
            if(cur.first + d[i][0] < x1 && cur.second + d[i][1] < y1 && cur.first + d[i][0] >=0 && cur.second + d[i][1] >=0){
                if(arr[cur.first + d[i][0]][cur.second + d[i][1]] == 'S'){
                    fail ++;
                }
            }else{
                num --;
            }
        }
        if(fail < (double)num/2.0){
            sum ++;
        }
    }
    cout << sum;
}