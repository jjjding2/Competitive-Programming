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

pii arr[200001];
int n;
int solve(int sad, int hat, int spot){
    if(spot == n-1){
        return sad + abs(hat - arr[spot].second);
    }
    int v1 = abs(hat - arr[spot].second); //don't switch
    int v2 = abs(arr[spot + 1].first - arr[spot].second); //switch
    
    if(v2 <v1 && hat - arr[spot+1].second < arr[spot+1].first - arr[spot+1].second){
        return solve(sad + v2, hat, spot + 1);
    }else{
        return(min( solve(sad + v1, arr[spot+1].first, spot + 1) , solve(sad + v2, hat, spot + 1)));
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    cout << solve(0, arr[0].first, 0);
    
}