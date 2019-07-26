#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int j, a;
int jersey[1000001];
bool vis[1000001];
int main(){
    cin >> j >> a;
    int count = 0;

    for(int i = 0; i<j; i++){
        char temp;
        cin >> temp;
        if(temp == 'S'){
            jersey[i] = 1;
        }
        else if(temp == 'M'){
            jersey[i] = 2;
        }
        else if(temp == 'L'){
            jersey[i] = 3;
        }
    }
    for(int i = 0; i<a; i++){
        char s;
        int sint;
        int n;
        cin >> s >> n;
        
        if(s == 'S'){
            sint = 1;
        }
        else if(s == 'M'){
            sint = 2;
        }
        else if(s == 'L'){
            sint = 3;
        }
        
        if(jersey[n-1]>=sint && vis[n-1] == 0){
            vis[n-1] = 1;
            count ++;
        }
    }
    cout << count;
}