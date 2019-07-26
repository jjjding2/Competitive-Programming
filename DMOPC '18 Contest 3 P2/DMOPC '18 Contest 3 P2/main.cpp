#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pii;
//{v, w}
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int fre[1000];
int eng[1000];

int sum[1000];
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%d", &fre[i]);
    }
    for(int i = 0; i<N; i++){
        scanf("%d", &eng[i]);
    }
    
    if(N>=1){
        sum[0] = max(fre[0], eng[0]);
    }
    if(N>=2){
        sum[1] = max(fre[0], eng[0]) + max(fre[1], eng[1]);
    }
    if(N>=3){
        sum[2] = max(sum[1] + min(fre[2], eng[2]), max(max(fre[2],eng[2]) + max(fre[1], eng[1]) + eng[0],  (max(fre[2],eng[2]) + max(fre[0], eng[0])) + eng[1]) );
    }
    
    for(int i = 3; i<N; i++){
        sum[i] = max(sum[i-1] + eng[i], max(max(fre[i],eng[i]) + max(fre[i-1], eng[i-1]) + eng[i-2] + sum[i-3],  (max(fre[i],eng[i]) + max(fre[i-2], eng[i-2])) + eng[i-1] + sum[i-2]) );

    }
    cout << sum[N-1];
}