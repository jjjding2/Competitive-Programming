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

int arr[21][21];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int x, y;
    scanf("%d%d", &x, &y);
    
    for(int i = 0; i<x; i++){
        for(int z = 0; z<y; z++){
            scanf("%d", &arr[i][z]);
        }
    }
    
    for(int z = y-1; z>=0; z--){
        for(int i = 0; i<x; i++){
            cout << arr[i][z];
            if(i != x - 1){
                cout << " ";
            }
        }
        cout << "\n";
    }
}