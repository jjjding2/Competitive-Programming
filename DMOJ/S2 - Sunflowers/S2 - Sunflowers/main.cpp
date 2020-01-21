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

int arr[1001][1001];
int N;
int temp[1001][1001];
void rots(){
    for(int i = 0; i<N; i++){
        for(int z = 0; z<N; z++){
            temp[i][z] = arr[i][z];
        }
    }
    for(int i =  0; i<N; i++){
        for(int z = 0; z<N; z++){
            int asdf = temp[z][N-1-i];
            arr[i][z] = temp[z][N-1-i];
        }
    }
}

int main(){
    scanf("%d", &N);
    int rot = 0;
    for(int i =0; i<N; i++){
        for(int z = 0; z<N; z++){
            scanf("%d", &arr[i][z]);
        }
    }
    if(arr[0][N-1] < arr[N-1][0]){
        rot = 1;
    }else if(arr[0][0] < arr[N-1][N-1] && arr[0][N-1]<arr[0][0]){
        rot = 2;
    }
    for(int i = 0; i<rot; i++){
        rots();
    }
    for(int i = 0; i<N; i++){
        for(int z = 0; z<N; z++){
            printf("%d", arr[i][z]);
            printf(" ");
        }
        printf("\n");
    }
}