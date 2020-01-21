#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pll;
typedef pair<long long, long long> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll  b, ll exp){if(exp == 0) return 1;ll t = fpow(b,exp/2);if(exp&1) return t*t*b;return t*t;}


plu arr[3001];



ll val[3001];
bool inset[3001];


int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%lld %lld", &arr[i].first, &arr[i].second);
    }
    int x;
    scanf("%d", &x);
    x = x -1;
    
    memset(val, 0x3f3f3f3f, sizeof(val));
    val[x] = 0;
    for(int temp = 0; temp<N; temp++){
        int mini = -1;
        ll minv = LONG_MAX;
        for(int z = 0; z<N; z++){
            if((val[z] < minv || mini == -1) && !inset[z]){
                minv = val[z];
                mini = z;
            }
        }
        if(mini == -1) break;
        inset[mini] = true;
        for(int z =0; z<N; z++){
                ll j =pow(abs(arr[z].first - arr[mini].first),2) + pow(abs(arr[z].second - arr[mini].second), 2);
                if(val[z] > val[mini] + j){
                    val[z] = val[mini] + j;
                }
            
            
        }
    }
    
    sort(val, val + N+1);
    int Q;
    scanf("%d", &Q);
    for(int i = 0; i<Q; i++){
        ll temp;
        scanf("%lld", &temp);
        int work = 0;
        int low = 0;
        int high = N-1;
        int mid = (low + high)/2;
        while(low <= high){
            mid = (low + high)/2;
            if(temp >=val[mid]){
                low = mid+1;
                work = mid;
            }else{
                high = mid - 1;
            }
        }
        printf("%d\n", work+1);
    }
    

    
}