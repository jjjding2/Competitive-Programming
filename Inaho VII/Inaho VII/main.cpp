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

int bit[500000];

int num;

int arr[500000];

void update(int x, int val){
    for(;x <= num; x += (x&-x)){
        arr[x] += val;
    }
}

int query(int x){
    int sum = 0;
    for(;x > 0; x -= (x&(-x))){
        sum += bit[x];
    }
    return sum;
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, T;
    
    scanf("%d%d", &N, &T);
    num = pow(20, 0.5);
    for(int z = 1; z<=num; z++){

        scanf("%d", &bit[z]);
    }
    
    if(T == 1){
        for(int i = 1; i<=num; i++){
            if(i == 1){
                printf("%d ", query(1));
            }else{
                printf("%d ", query(i) - query(i - 1));
            }
        }
    }else{
        for(int i = 1; i<=num; i++){
            update(i, bit[i]);
        }
        for(int i = 1; i<=num; i++){
            printf("%d ", arr[i]);
        }
    }
    
}