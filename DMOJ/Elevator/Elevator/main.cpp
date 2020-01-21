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

struct edge{int t; int a; int b;};

edge arr[101];

int spota[101][101];
int spotb[101];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, t;
    scanf("%d%d", &n, &t);
    
    int m;
    scanf("%d", &m);
    for(int i = 1; i<=m; i++){
        scanf("%d%d%d", &arr[i].t, &arr[i].a, &arr[i].b);
    }
    int waiting = 0;
    int sum = 0;
    int curtime = 0;
    int count = 1;
    
    for(int i = 0; i<=n; i++){
        sum += t * waiting;
        while(count <= m && arr[count].t <= curtime){
            spota[arr[count].a][arr[count].b] ++;
            waiting ++;
            count ++;
        }
        for(int z = 0; z<=n; z++){
            spotb[ z ] += spota[i][z];
            spota[i][z] = 0;
        }
        waiting -= spotb[i];
        spotb[i] = 0;
        curtime += t;
        if(waiting == 0 && count > m){
            break;
        }
        cout << i << " ";
        if(i == n){
            i = i-1;
            for(; i>= 0; i--){
                sum += t * waiting;
                while(count <= m && arr[count].t <= curtime){
                    spota[arr[count].a][arr[count].b] ++;
                    waiting ++;
                    count ++;
                }
                for(int z = 0; z<=n; z++){
                    spotb[ z ] += spota[i][z];
                    spota[i][z] = 0;
                }
                waiting -= spotb[i];
                spotb[i] = 0;
                
                curtime += t;
                if(waiting == 0 && count > m){
                    break;
                }
                cout << i << " ";

            }
            i = i + 1;
        }
    }
    cout << sum;
    
}