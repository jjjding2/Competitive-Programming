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

pii item[201];

int arr[20001][2];

int freq[20001];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
        for(int i = 0; i<n; i++){
            scanf("%d", &item[i].first);
        }
    for(int i = 0; i<n; i++){
        scanf("%d", &item[i].second);
    }
    int k;
    scanf("%d",&k);
    int c = 0;
    int p = 1;
    
    memset(arr, INF, sizeof(arr));
    memset(freq, INF, sizeof(freq));
    freq[0] = 0;
    arr[0][c] = 0;
    arr[0][p] = 0;
    for(int i = 0; i<n; i++){
        for(int z = 1; z<=k; z++){
            

            if(z >= item[i].first && freq[z-item[i].first] + 1<= item[i].second && arr[z - item[i].first][c] + 1 < arr[z][c]){
                arr[z][c] = arr[z-item[i].first][c] + 1;
                freq[z] = freq[z - item[i].first] + 1;
            }
            if(z >= item[i].first && (arr[z - item[i].first][p] + 1 <= arr[z][c]) && freq[z] != 0){
                arr[z][c] = arr[z - item[i].first][p] + 1;
                freq[z] = 1;
            }
            if(arr[z][p] <= arr[z][c]){
                arr[z][c] = arr[z][p];
                freq[z] = 0;
            }
        }
        p ++;
        p = p %2;
        c ++;
        c = c%2;
        memset(freq, INF, sizeof(freq));
        freq[0] = 0;
    }
    cout << arr[k][p];
    
    
    
    
}