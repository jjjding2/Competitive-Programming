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

int a, b, c, d;
int q;

int arr[100001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &q);
    arr[0] = 1;
    for(int i = 1; i<100001; i++){
        int sum1 = 0;
        int sum2 = 0;
        if((int)(i/a - b) >= 0){
            sum1 = arr[i/a - b];
        }else{
            sum1 = 1;
        }
        if((int)(i/c - d) >= 0){
            sum2 = arr[i/c - d];
        }else{
            sum2 = 1;
        }
        arr[i] = sum1 + sum2;
    }
    
    for(int i = 0; i<q; i++){
        int as;
        scanf("%d", &as);
        if(as <= 1000000){
            printf("%d\n", arr[as]);
        }else{
            for(int z = 0; z<as; z++){
                
            }
        }
    }
    
    
}