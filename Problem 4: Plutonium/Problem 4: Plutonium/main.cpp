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

int arr[2001];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
        if(arr[i] == 0 ){
            arr[i] = -1;
        }
    }
    for(int i = N-1; i>= 0; i--){
        if(arr[i] > 0){
            int val = arr[i]-1;
            for(int z = i-1; z> i - arr[i]; z--){
                if(arr[z] != -1 && arr[z] != val){
                    printf("-1");
                    return 0;
                }else{
                    arr[z] = val;
                }
                val -= 1;
            }
            i = i - arr[i] + 1;
        }
    }
    int sum = 0;
    int sum2 = 0;
    for(int i = 1; i<N; i++){
        if(arr[i] == 1){
            sum ++;
        }
        if(arr[i] == -1){
            sum2 ++;
        }
    }
    printf("%d", sum);
    printf(" ");
    printf("%d", sum + sum2);
}