#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int arr[100000][2];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N, M, N1, M1;
    scanf("%d%d%d%d", &N, &M, &N1, &M1);
    
    bool g1 = false;
    bool g2 = false;
    
    for(int i = 0; i<20*20*5; i ++ ){
        arr[i][0] = arr[i-1][0];
        arr[i][1] = arr[i-1][1];

        if(i % M == 0 || i == 0){
            arr[i][0] ++;
            if(arr[i][0] == N1){
                g1 = true;
            }
        }
        
        if(i % M1 == 0 || i == 0){
            arr[i][1] ++;
            if(arr[i][1] == N){
                g2 = true;
            }
        }
        if(g1 && g2 == true){
            cout << -1;
            break;

        }else if(g1 == true){
            cout << 1;
            break;

        }else if(g2 == true){
            cout << 2;
            break;
        }
    }
    
    
}