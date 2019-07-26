#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

struct edge{int n; int v;};
edge arr[300001];

int spot[300001];

bool cmp(edge a, edge b){
    if(a.n != b.n){
        return a.n < b.n;
    }else{
        return a.v > b.v;
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, M, K;
    scanf("%d%d%d", &N, &M, &K);
    
    for(int i = 0; i<N; i++){
        int n, v;
        scanf("%d%d", &n, &v);
        arr[i] = {n, v};
    }
    sort(arr, arr + N, cmp);
    ll maxv = 0;

    int count = 2;
    maxv += arr[0].v;
    M--;
    spot[1] = 1;
    for(int i = 1; i<N; i++){
        if(arr[i].n != arr[i - 1].n){
            spot[count] = i+1;
            M--;
            maxv += arr[i].v;
            count ++;
        }
    }
    bool work = true;
    while(M!= 0 && work == true){
        work = false;
        ll maxnum = 0;
        int index = 0;
        for(int i = 1; i<=K; i++){
            if(arr[spot[i]].n == i && arr[spot[i]].v > maxnum){
                maxnum = arr[spot[i]].v;
                index =i;
            }
        }
        if(index != 0){
            work = true;
            maxv += maxnum;
            spot[index] ++;
            M--;
        }
    }
    
    
    cout << maxv;
    
    
}