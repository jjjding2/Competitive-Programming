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

int arr[100000];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, K;
    scanf("%d%d", &N, &K);
    
    int f= 0;
    int cur = 0;
    while(N > 0){
        arr[f] = N%2;
        cur += N%2;
        N = N/2;
        f ++;
    }
    if(cur <= K){
        for(int i = f-1; i>= 0; i --){
            if(arr[i] > 0 && i != 0){
                int temp = K - cur;

                if(2*arr[i] - arr[i] + cur <= K){
                    arr[i - 1] += 2 * arr[i];
                    cur += 2 * arr[i];
                    cur -= arr[i];
                    arr[i] = 0;
                }else if(cur + 2 * temp - temp<= K){
                    arr[i - 1] += 2 * temp;
                    cur += 2*temp;
                    cur -= temp;
                    arr[i] -= temp;
                }
            }
        }
    }
    if(cur == K){
        printf("YES\n");
        int temp = 1;
        for(int i = 0; i<f; i++){
            for(int z = 0; z<arr[i]; z++){
                printf("%d", temp);
                if(i != f - 1 || z != arr[i]-1){
                printf(" ");
                }
            }
            temp = temp * 2;
        }
    }else{
        printf("NO\n");
    }

    
}
