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

int pos[100001];
int neg[100001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("mountains.in","r",stdin); freopen("mountains.out","w",stdout);
    
    int N;
    
    cin >> N;
    for(int i = 0; i<N; i++){
        int a, b;
        cin >> a >> b;
        pos[i] = b - a;
        neg[i] = a + b;
    }
    int tot = N;
    for(int i = 0; i<N; i++){
        for(int z = 0; z<N; z++){
            if(i != z){
                
                if(pos[z] >= pos[i] && neg[z] >= neg[i]){
                    tot --;
                    break;
                }
                
            }
        }
    }
    cout << tot;
    
}