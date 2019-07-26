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

ll arr[1000001];

int n, m, c;
bool work(ll num){
    
    ll first = arr[0];
    ll firsti = 0;
    int mv = 1;
    for(int i =1; i<n; i++){
        if(arr[i] - first > num || i - firsti + 1> c){
            first = arr[i];
            firsti = i;
            mv ++;
        }
    }
    if(mv <= m){
        return true;
    }else{
        return false;
    }
    
}

int main(){
    freopen("convention.in","r",stdin); freopen("convention.out","w",stdout);
    
    scanf("%d%d%d", &n, &m, &c);
    
    for(int i = 0; i<n; i++){
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    
    ll lo = 0;
    ll hi = arr[n - 1] - arr[0] + 1;
    ll mid = (lo + hi)/2;
    ll good = -1;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(work(mid)){
            good = mid;
            hi = mid - 1;
            
        }else{
            lo = mid + 1;
        }
    }
    printf("%lld\n", good);
    
}