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

int L1, G1;
int arr[1000000];

int main(){
    
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d%d", &L1, &G1);
    int index = -1;
    while(L1 >= 0){
        index ++;
        L1 -= arr[index];
    }
    sort(arr, arr + index);

    int i = 0;
    for(i = 0; i<index; i++){
        G1 = G1 - arr[i];
        if(G1 < 0){
            break;
        }
    }
    printf("%d", index - i);
}