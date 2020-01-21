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

string arr1[1000];

string arr[1000];

vector <int> adj[30];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    for(int a = 0; a<10; a++){
        for(int b = 0; b<10; b++){
            for(int c = 0; c<10; c++){
                if(a*100 + b * 10 + c == pow((a + b + c), 3)){
                    cout << a << b << c << "\n";
                }
            }
        }
    }
    
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr1[i];
        
    }
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        arr[i] = arr1[x-1];
    }
    for(int i = 0; i<n; i+= 2){
        int x  =i;
        while(arr[i][x] == arr[i+1][x]){
            x ++;
        }
    }
    
    
}
