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

int arr[100000];

int sum = 0;

int minv(int index, int val){
    if(index == 0){
        return abs((sum - val) -val);
    }
    
    return(min(minv(index-1, val + arr[index - 1]), minv(index - 1, val)));
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    cout << minv(N, 0);
}