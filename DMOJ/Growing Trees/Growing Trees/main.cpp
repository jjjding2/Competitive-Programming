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

int rate[1001];

int N;

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d%d", &arr[i], &rate[i]);
    }
    int minv = INF;
    for(int i = 0; i<N; i++){
        for(int z = 0; z<N; z++){
            if(z!= i){
                if((rate[z] - rate[i])!=0){

                    if((arr[i] - arr[z])%(rate[z] - rate[i]) == 0){
                        int temp =(arr[i] - arr[z])/(rate[z] - rate[i]);
                        if(temp < minv && temp >= 0){
                            minv = temp;
                        }
                    }
                }else if(arr[i] == arr[z]){
                    minv = 0;
                }
            }
        }
    
    }
    if(minv == INF){
        printf("-1");
    }else{
        printf("%d", minv);
    }
}