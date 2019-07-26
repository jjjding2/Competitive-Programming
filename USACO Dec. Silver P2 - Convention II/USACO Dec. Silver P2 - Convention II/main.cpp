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

struct edge{int a; int t; int s;};

edge arr[100001];

bool cmpByTime(edge a, edge b){
    return a.a < b.a;
}

bool cmpByS(edge a, edge b){
    return a.s < b.s;
}


int main(){
    freopen("convention2.in","r",stdin); freopen("convention2.out","w",stdout);
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d%d", &arr[i].a, &arr[i].t);
        arr[i].s = i;
    }
    
    sort(arr, arr + N, cmpByTime);
    
    int time = arr[0].a;
    int set = 0;
    int maxv = 0;
    for(int i = 0; i<N; i++){
        if(time - arr[i].a > maxv){
            maxv = time - arr[i].a;
        }
        if(arr[i].a > time){
            time = arr[i].a;
        }
        time +=arr[i].t;
        for(int z = set; z < N; z++){
            if(arr[z].a > time){
                set = z;
                break;
            }
        }

        if(i < set){
            sort(arr + i + 1, arr + set, cmpByS);
        }
        
    }
    printf("%d", maxv);
    
}