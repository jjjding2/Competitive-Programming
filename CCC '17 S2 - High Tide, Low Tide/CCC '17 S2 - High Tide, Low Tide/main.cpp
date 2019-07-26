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

int arr[101];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    bool oof = false;
    if(n%2 == 1){
        oof = true;
        n ++;
    }
    for(int i = 0; i<n/2; i++){
        if(oof == true && i == n/2 - 1){
            cout << arr[n/2 - i-1];
        }else{
        cout << arr[n/2 - i-1] << " " << arr[i + n/2] << " ";
        }
    }
    cout << "\n";
}