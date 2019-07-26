#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;

typedef pair<ll, ll> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

pii arr[2001];

bool cmp(pii a, pii b){
    return a.first > b.first;
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, D;
    scanf("%d%d", &N, &D);
    
    ll tot = 0;
    for(int i = 0; i<N; i++){
        scanf("%lld", &arr[i].first);
        arr[i].second = i+1;
        tot += arr[i].first;
    }
    sort(arr, arr + N, cmp);
    ll cursum = 0;
    for(int i = 0; i<N; i++){
        cursum += arr[i].first;
        if(cursum > tot/2){
            printf("%d\n", i + 1);
            break;
        }
    }
    for(int z = 0; z<D; z++){
        ll a, b;
        scanf("%lld%lld", &a, &b);
        for(int i = 0; i<N; i++){
            if(arr[i].second == a){
                tot -= arr[i].first;
                tot += b;
                arr[i].first = b;
                break;
            }
        }
        sort(arr, arr + N, cmp);
        ll cursum = 0;
        for(int i = 0; i<N; i++){
            cursum += arr[i].first;
            if(cursum > tot/2){
                printf("%d\n", i + 1);
                break;
            }
        }
    
    }
    
    
    
}