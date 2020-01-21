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

int dp[1000][1000];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    string a, b;
    cin >> a >> b;
    
    for(int i = 1; i<=a.length(); i++){
    
        for(int z = 1; z<=b.length(); z++){
            if(a[i-1] != b[z-1]){
                dp[i][z] = max(dp[i - 1][z], dp[i][z-1]);
            }else if(a[i-1] == b[z-1]){
                dp[i][z] = dp[i-1][z-1] + 1;
            }
            
        }
        
    }
    int h = (int)a.length();
    int w = (int)b.length();
    
    string temp = "";
    int count = 0;
    while(count < dp[a.length()][b.length()] && h >= 1 && w >= 1){
        if(dp[h - 1][w] < dp[h][w] && dp[h][w-1] < dp[h][w]){
            h = h - 1;
            w = w - 1;
            temp =  a.substr(h, 1) + temp;
            count ++;
        }else if(dp[h][w - 1] == dp[h][w]){
            w = w -1;
        }else{
            h = h - 1;
        }
    }
    cout << temp;
    
    
    
    
}