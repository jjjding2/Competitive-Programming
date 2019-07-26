#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;

typedef pair<ll, ll> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


pii cur[101];

pii newv[3][101];

double area(pii p1, pii p2, pii p0){
    return 0.5*abs(p0.first*(p1.second - p2.second) + p1.first*(p2.second - p0.second) + p2.first*(p0.second - p1.second));

}


int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M;
    
    scanf("%d%d", &N, &M);
    
    for(int i = 0; i<N; i++){
        scanf("%lld%lld", &cur[i].first, &cur[i].second);
    }
    
    for(int i = 0; i<M; i++){
        scanf("%lld%lld%lld%lld%lld%lld", &newv[0][i].first, &newv[0][i].second, &newv[1][i].first, &newv[1][i].second, &newv[2][i].first, &newv[2][i].second);
        
        
        double cura = area(newv[0][i], newv[1][i], newv[2][i]);
        int sum = 0;
        for(int z = 0; z<N; z++){

            if( area(cur[z], newv[1][i], newv[2][i]) + area(newv[0][i], cur[z], newv[2][i]) + area(newv[0][i], newv[1][i], cur[z])  == cura){
                sum ++;
            }
            
        }
        printf("%d\n", sum);

    }
    
    
}