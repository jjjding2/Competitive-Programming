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

int visx[1000009];
int visy[1000009];

int main(){
    int x, y;
    scanf("%d%d", &x, &y);
    int V, H, C;
    scanf("%d%d%d", &V, &H, &C);
    
    int maxv = 0;
    
    for(int i = 0; i<V; i++){

        int x;
        scanf("%d", &x);
        if(x > maxv){
            maxv = x;
        }
        visy[x] = 1;
    }
    for(int i = 1; i<=1000001; i++){
        visy[i] = visy[i-1] + visy[i];
    }
    
    maxv = 0;
    for(int i = 0; i<H; i++){
        int x;
        scanf("%d", &x);
        if(x > maxv){
            maxv = x;
        }
        visx[x] = 1;
    }
    for(int i = 1; i<=1000001; i++){
        visx[i] = visx[i-1] + visx[i];
    }
    for(int i = 0; i<C; i++){
        int tempx, tempy;
        scanf("%d%d", &tempx, &tempy);
        if(visy[max(tempx, x)] - visy[min(tempx, x)] != 0){
            printf("N\n");
        }else if(visx[max(tempy, y)] - visx[min(tempy, y)] != 0){
            printf("N\n");
        }else{
            printf("Y\n");
        }
        
    }
}