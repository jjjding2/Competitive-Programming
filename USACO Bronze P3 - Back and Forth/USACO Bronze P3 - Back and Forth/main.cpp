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

int sum = 0;

int vis[10000];

void arr(int day, int good1[], int good2[], int curv){
    if(day == 4){
        if(!vis[curv]){
            sum += 1;
        }
        vis[curv] = true;
        return;
    }else if(day%2 == 0){ //barn 1
        for(int i = 1; i<= 100; i++){
            if(good1[i] > 0){
                good1[i] -= 1;
                good2[i] += 1;
                arr(day + 1, good1, good2, curv - i);
                good2[i] -= 1;
                good1[i] += 1;
            }
        }

    }else{//barn 2
        for(int i = 1; i<= 100; i++){
            if(good2[i] > 0){
                good2[i] -= 1;
                good1[i] += 1;
                arr(day + 1, good1, good2, curv + i);
                good1[i] -= 1;
                good2[i] += 1;
            }
        }
    }
}

int temp1[1000];
int temp2[1000];

int main(){
    freopen("backforth.in","r",stdin); freopen("backforth.out","w",stdout);

    for(int i = 0; i<10; i++){
        int temp;
        scanf("%d", &temp);
        temp1[temp] += 1;
    }
    for(int i = 0; i<10; i++){
        int temp;
        scanf("%d", &temp);
        temp2[temp] += true;
    }
    
    arr(0, temp1, temp2, 1000);
    printf("%d", sum);
}