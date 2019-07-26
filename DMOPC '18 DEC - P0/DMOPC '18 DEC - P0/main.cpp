#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int arr[4][4];

int main(){
    int R, X, Y;
    cin >> R >> X >> Y;
    
    int maxv = 1000000;
    int mini = - 1;
    for(int i = 0; i<3; i++){
        cin >> arr[0][i] >> arr[1][i] >> arr[2][i];
        if(arr[2][i] < maxv){
            maxv = arr[2][i];
            mini = i;
        }
    }
    if(pow(arr[0][mini] - X, 2) + pow(arr[1][mini] - Y, 2) < R*R){
        cout << "What a beauty!";
    }else{
        cout << "Time to move my telescope!";
    }
    
}