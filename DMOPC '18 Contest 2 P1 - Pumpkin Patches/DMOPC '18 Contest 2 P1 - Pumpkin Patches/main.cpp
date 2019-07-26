#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

int arrx[1000000];
int arry[1000000];

int main(){
    int N;
    scanf("%d", &N);
    int minx = 2147483647;
    int maxx = 0;
    int miny = 2147483647;
    int maxy = 0;
    
    for(int i = 0; i<N; i++){
        int x;
        int y;
        scanf("%d %d", &x, &y);
        if(x < minx){
            minx = x;
        }
        if(x > maxx){
            maxx = x;
        }
        if(y <miny){
            miny = y;
        }
        if(y > maxy){
            maxy = y;
        }
    }
    cout << 2*(maxx - minx) + 2*(maxy - miny);
}