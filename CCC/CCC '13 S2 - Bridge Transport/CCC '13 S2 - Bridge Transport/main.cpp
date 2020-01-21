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

int arr[100001];

int main(){
    int N, W;
    scanf("%d%d", &W, &N);
    for(int i =0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        if(i!= 0){
            arr[i] = arr[i-1] + temp;
        }else{
            arr[i] = temp;
        }
    }
    if(N >= 4){
        for(int i = 0; i<4; i++){
            if(arr[i] > W){
                cout << i << "\n";
                return 0;
            }
        }
    }
    for(int i = 0; i<=N-4; i++){
        if(arr[i + 4] - arr[i] > W){
            cout << i + 4 << "\n";
            return 0;
        }
    }
    cout << N;
}