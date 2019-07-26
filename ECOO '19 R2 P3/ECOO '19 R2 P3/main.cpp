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

ll n,m;
ll p,arr[10000001];char c;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA32.txt","r",stdin);
    for(int z = 0;z<10;z++){
        cin >> n >> m;
        if(n > 1000){
            cout << 1 << " " << n << "\n";
            for(int i = 0;i<m;i++){
                int a, b;
                cin >> a >> b;
                
            }
        }else{
            for(int i = 1;i<=n;i++){
                arr[i] = 1;
            }
            for(int i = 0;i<m;i++){
                cin >> p >> c;
                if(c == 'L'){
                    ll p1 = p-1,p2 = p;
                    while(p1>=1 && p2 <=n*10){
                        arr[p2] += arr[p1];
                        arr[p1] = 0;
                        p1--;p2++;
                    }
                }
                else{
                    ll p2 = p+1,p1 = p;
                    while(p1 >= 1 && p2<= n*10){
                        arr[p1] += arr[p2];
                        arr[p2] = 0;
                        p1--;p2++;
                    }
                }
            }
            ll cnt = 0,ma = 0;
            for(int i = 1;i<=n*2;i++){
                ma = max(ma,arr[i]);
                if(arr[i] > 0){cnt++;}
            }
            cout << cnt << " " << ma << "\n";
        }
    }
}
