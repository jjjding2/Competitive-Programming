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

int arr[1001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr + N);
    
    for(int i = 0; i<N; i++){
        if(i != N-1 && arr[i] == arr[i + 1] - 1){
            int start = i;
            int count = 0;
            while(arr[i] == arr[i + 1] - 1){
                i ++;
                count ++;
            }
            if(count > 1){
                printf("%d", arr[start]);
                
                printf("-");
                printf("%d", arr[i]);
                if(i != N-1){
                    printf(" ");
                }

            }else{
                i = start;
                printf("%d", arr[i]);
                if(i != N-1){
                    printf(" ");
                }
            }

        }else{
            printf("%d", arr[i]);
            if(i != N-1){
                printf(" ");
            }
        }
    
    }
    
    
}