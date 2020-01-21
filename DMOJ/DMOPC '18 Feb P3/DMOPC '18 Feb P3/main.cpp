#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f




unsigned long long psa[200005];

unsigned long long m;
long long n;


bool works(long long mid){
    for(int i = 1; i<= n - mid; i++){
        if(psa[i + mid] - psa[i] < m){
            return true;
        }
    }
    return false;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%lld%llu", &n, &m);

    for(long long i = 1; i<=n; i++){
        unsigned long long temp;
        scanf("%llu", &temp);
        psa[i] = psa[i - 1] + temp;
    }
    
    long long low = 0;
    long long high = n;
    long long mid = (low + high)/2;
    
    unsigned long long ans = 0;
    
    while(low <= high){
        mid = (low + high)/2;
        if(works(mid)){
            if(mid > ans){
                ans = mid;
            }
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    if(n == 1 && psa[1] < m){
        printf("%d", 1);
    }else{
        printf("%llu", ans);
    }
    
    
}