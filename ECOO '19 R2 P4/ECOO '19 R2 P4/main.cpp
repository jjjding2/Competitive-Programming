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

ll arr[1000001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA42.txt","r",stdin);
    for(int z = 0; z<10; z++){
        int n, r, s;
        cin >> n >> r >> s;
        
        bool one = true;
        ll onecount = 0;
        ll maxv = 0;
        ll count = 0;
        for(int i = 0; i<n; i++){
            cin >> arr[i];
            count += arr[i];
            maxv = max(maxv, arr[i]);
            if(arr[i] > 1){
                one = false;
            }else if(arr[i] == 1){
                onecount ++;
            }
        }
        
        if(one){
            if(r >= s){
                cout << onecount*s + r*onecount << "\n";
            }else if(count == 0){
                cout << 0 << "\n";
                
            }else{
                int first = 0;
                while(arr[first] == 0 && first < n){
                    first ++;
                }
                int second = n - 1;
                while(arr[second] == 0 && second >= 0){
                    second --;
                }
                cout << (second - first+1)*r + s << "\n";
            }
        }else{
            if(r >= s){
                cout << count*s + r * count<< "\n";
            }else{
                int first = 0;
                while(arr[first] == 0){
                    first ++;
                }
                int second = n - 1;
                while(arr[second] == 0){
                    second --;
                }
                cout << ((second - first)*r + s)*maxv << "\n";
            }
        }
        
    }
    
}
