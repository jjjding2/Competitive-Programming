#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


int clubs[1005];

int dis[5285];

int main(){
    int D;
    int N;
    scanf("%d %d", &D, &N);
    for(int i = 0; i<N; i++){
        cin >> clubs[i];
        dis[clubs[i]] = 1;
    }
    sort(clubs, clubs + N);
    for(int i = 0; i<=D; i++){
        for(int x = 0; x<N; x++) {
            if((i-clubs[x] >= 0 && (dis[i-clubs[x]] +  1 < dis[i]||dis[i] == 0) && dis[i-clubs[x]] != 0)){
                dis[i] = dis[i-clubs[x]] + 1;
            }
        }
    }
    if(dis[D]>0){
        cout << "Roberta wins in " << dis[D] << " strokes.";
    }else{
        cout << "Roberta acknowledges defeat.";

    }
}