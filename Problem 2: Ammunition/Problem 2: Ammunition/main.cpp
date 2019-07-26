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

int arr[1001];

int main(){
    int N, M, S;
    scanf("%d%d%d", &N, &M, &S);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    if(S == 0){
        cout << 0;
    }else{
        for(int i = 0; i<N; i++){
            S += min(arr[i], M);
        }
        cout << min(N, S);

    }
}