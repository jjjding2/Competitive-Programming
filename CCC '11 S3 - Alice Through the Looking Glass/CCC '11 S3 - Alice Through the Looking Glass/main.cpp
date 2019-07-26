#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int check(int M, int x, int y){
    int x1 = x/pow(5, M-1);
    int y1 = y/pow(5, M-1);
    if(x1 == 1 && y1 == 0){
        return 0;
    }
    else if(x1 == 2 && y1 == 0){
        return 0;
    }
    else if(x1 == 3 && y1 == 0){
        return 0;
    }
    else if(x1 == 2 && y1 == 1){
        return 0;
    }
    else if(x1 == 1 && y1 == 1){
        return(check(M-1, x%(int)pow(5, M-1), y%(int)pow(5, M-1)));
    }
    else if(x1 == 2 && y1 == 2){
        return(check(M-1, x%(int)pow(5, M-1), y%(int)pow(5, M-1)));
    }
    else if(x1 == 3 && y1 == 1){
        
        return(check(M-1, x%(int)pow(5, M-1), y%(int)pow(5, M-1)));
    }else{
        return 1;
    }
    
}

int main(){
    int N;
    scanf("%d", &N);
    
    /*
     0 - Yes
     1 - No
     2 - Maybe
     
    */
    
    for(int i = 0; i<N; i++){
        int M, x, y;
        
        scanf("%d %d %d", &M, &x, &y);
        if(check(M, x, y) == 0){
            cout << "crystal" << "\n";
        }else{
            cout << "empty" << "\n";
        }
    }
    
}