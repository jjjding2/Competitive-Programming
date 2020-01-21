#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

/*
void add(int x){
    
    auto hi = start.upper_bound(x), lo = hi; lo--;  //finds the index of higher and lower value (can't use lower_bound because it doesnt find a lower value)
    int hival = *hi, loval = *lo; //turns auto into int
    if(--len[hival - loval] == 0) len.erase(hival - loval);     //if there is only one value with the same length, remove it
    len[hival - x] ++; len[x - loval] ++; start.insert(x);  //add the length to the right and the left of the inserted element
    
}

void rem(int x){
    auto hi = start.upper_bound(x), lo = hi; lo --; lo --;
    int hival = *hi, loval = *lo;
    if(--len[hival - x] == 0) len.erase(hival - x);
    if(--len[x - loval] == 0) len.erase(x - loval);
    len[hival - loval] ++; start.erase(x);
}

int main(){
    
    scanf("%d%d", &N, &Q);
    start.insert(1);
    a[0] = 1e9+1;
    for(int i = 1; i<=N; i++){
        scanf("%d", &a[i]);
        if(i > 1 && a[i] < a[i - 1]){
            len[i - pre] ++; start.insert(i); pre = i;
        }
        
    }
    start.insert(N + 1); len[N+1-pre] ++;
    printf("%d\n", len.rbegin()->first);
    
    for(int i = 1, x, y; i <= Q; i++){
        scanf("%d %d", &x, &y); a[x] = y;
        if(!start.count(x) && a[x] < a[x-1]) add(x);
        else if(start.count(x) && a[x] >= a[x-1]) rem(x);
        
        if(!start.count(x+1) && a[x + 1] < a[x]) add(x + 1);
        else if(start.count(x + 1) && a[x + 1] >= a[x]) rem(x+1);
        printf("%d\n", len.rbegin()->first);
    }
    
}
*/
int N, Q, a[400003]; set<int> start; map<int, int> len;
int pre = 1;



int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N, Q;
    scanf("%d%d", &N, &Q);
    for(int i = 1; i<=N; i++){
        scanf("%d", &a[i]);
    }
    start.insert(1);
    a[0] = 10e9;
    for(int i = 1; i<N; i++){
        if(a[i+1] < a[i] && i > 1){
            start.insert(i);
            len[i - pre] ++;
            pre = i;
        }
    }
    start.insert(N + 1); len[N + 1 - pre] ++;
    
    for(int i = 0; i<Q; i++){
        
        int a, b;
        scanf("%d%d", &a, &b);
        
        a[a] =b;
        
        
    }
}


