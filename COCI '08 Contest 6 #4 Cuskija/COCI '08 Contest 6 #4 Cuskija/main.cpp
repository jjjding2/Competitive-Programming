#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;
int arr[100][3];

int c[1][3];

vector<int> print;
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int x;
        scanf("%d", &x);
        c[0][x%3] += 1;
        arr[ c[0][x%3]-1 ][x%3] = x;
    }
    if(c[0][0] == 0){
        if(c[0][1] != 0 && c[0][2] == 0){
            while( c[0][1] != 0){
                print.push_back(arr[ c[0][1]-1 ][1]);
                c[0][1] --;
            }
        }else if(c[0][2] != 0 && c[0][1] == 0){
            while( c[0][2] != 0){
                print.push_back(arr[ c[0][2]-1 ][2]);
                c[0][2] --;
            }
        }else{
            cout << "impossible";
            return 0;
        }
    }
    while(c[0][0] != 0 || c[0][1] != 0 || c[0][2]!=0){
        if(c[0][0]>1){
            print.push_back(arr[ c[0][0] - 1][0]);
            c[0][0] --;
            if(c[0][1] != 0){
                print.push_back(arr[ c[0][1]-1 ][1]);
                c[0][1] --;
            }else if(c[0][2] != 0){
                print.push_back(arr[ c[0][2]-1 ][2]);
                c[0][2] --;
            }else if(c[0][0] != 0 || c[0][1] != 0 || c[0][2]!=0){
                cout << "impossible";
                return 0;
            }
        }else if(c[0][0] == 1){
            while( c[0][1] != 0){
                print.push_back(arr[ c[0][1]-1 ][1]);
                c[0][1] --;
            }
            print.push_back(arr[ c[0][0] - 1][0]);
            c[0][0] --;
            while( c[0][2] != 0){
                print.push_back(arr[ c[0][2]-1 ][2]);
                c[0][2] --;
            }
        }
    }
    
    while(!print.empty()){
        cout << print.front() << " ";
        print.erase(print.begin());
    }
}