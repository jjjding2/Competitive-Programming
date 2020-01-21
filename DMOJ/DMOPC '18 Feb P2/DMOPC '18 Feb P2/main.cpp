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

double arr[1001][1001];

double ans, sum, n, m;

double den = 1;

int work(double mid){
    double sum = 0;
    for(int i = 0; i<n; i++){
        for(int z = 0; z<m; z++){
            if(arr[i][z] * mid <= 1.0000000){
                sum += arr[i][z]*mid;
            }else{
                sum += 1;
            }
        }
    }
    
    double result = sum/den;
    result = round(result*100000000.0)/100000000.0;
    
    if(result < 0.4800000){
        return 0;
    }else if(result > 0.4800000){
        return 1;
    }else{
        return 2;
    }
}

void solve(){
    
    double lo = 0.48/ans;
    double hi = 3000;
    double mid = (lo + hi)/2.0;
    
    while(true){
        mid = (lo + hi)/2.0;
        int temp = work(mid);
        
        if(temp == 0){
            lo = mid + 0.00001;
        }else if(temp == 1){
            hi = mid - 0.00001;
        }else{
            printf("%lf", mid);
            break;
        }
    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%lf%lf", &n, &m);
    den = n*m;
    sum = 0;
    
    for(int i = 0; i<n; i++){
        for(int z = 0; z<m; z++){
            scanf("%lf", &arr[i][z]);
            sum += arr[i][z];
        }
    }
    
    double result = sum/den;
    ans = result;
    result = round(result*100000.0)/100000.0;
    if(result < 0.48){
        printf("underexposed\n");
        solve();
        
    }else if(result > 0.48){
        printf("overexposed\n");
        solve();
    }else{
        printf("correctly exposed\n");
    }
    
    
    
}