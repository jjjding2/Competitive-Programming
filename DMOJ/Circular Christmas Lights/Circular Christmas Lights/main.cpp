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
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}


//1: x0,x1,x2,x3,x4
//2: x0^x1, x1^x2, x2^x2 ...
//3: x0^x2, x1^x3, x2^x4
//4: x0^x^x4

//pick only powers of k
//xi^x(i + 2^k)%n
int arr[1000][2];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, m;
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int x;
        cin >> arr[i][0];
        arr[i][1] = arr[i][0];
        
    }
    int a = 0;
    int b = 1;
    
    for(int i = 0; i<1000; i++){
        int val = 0;
        for(int z = 0; z<n; z++){
            if(z == n-1){
                if(arr[0][a] == 1){
                    arr[z][b] = (arr[z][b] + 1)%2;
                }
                cout << arr[z][b] << " ";
                
            }else{
                if(arr[z + 1][a] == 1){
                    arr[z][b] = (arr[z][b]+ 1)%2;
                    
                }
                cout << arr[z][b] << " ";

            }
            if(arr[z][b] == 1){
                val ++;
            }
            
        }
        for(int z = 0; z<n; z++){
            arr[z][a] = arr[z][b];
        }
        a = (a + 1)%2;
        b = (b + 1)%2;
        cout << " :" << val << " ";
        cout << "\n";
    }

    
}
