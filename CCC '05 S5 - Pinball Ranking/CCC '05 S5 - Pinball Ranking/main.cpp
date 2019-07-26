#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<long long, long long> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


ll bit[100001];

int N;

pii arr[100001];

void update(ll x, ll val){
    for(;x <= N; x += (x&-x)){
        bit[x] += val;
    }
}

ll query(ll x){
    ll sum = 0;
    for(;x >  0 ; x -= (x&-x)){
        sum += bit[x];
    }
    return sum;
}
bool cmp(pii x, pii y){
    return x.first > y.first;
}

bool cmp2(pii x, pii y){
    return x.second > y.second;
}


int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d", &N);
    
    double sum = 0;
    
    for(int i = 1; i<=N; i++){
        scanf("%lld", &arr[i].first);
        arr[i].second = i;
       
    }
    arr[0].first = INF;
    sort(arr, arr + N+1, cmp);
    
    for(int i = 1; i<N; i++){
        bool oof = false;
        int temp = i;
        while(arr[i].first == arr[i + 1].first && i + 1 <= N){
            i ++;
            oof = true;
        }
        if(oof){
            sort(arr + temp, arr + i+1, cmp2);
        }
        i = temp;
    }
    
    for(int i = 1; i<=N; i++){
        sum += query(arr[i].second)+1;

        update(arr[i].second, 1);

    
    }
    printf("%.2f", sum/N);
    
    
}