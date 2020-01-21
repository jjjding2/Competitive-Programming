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


int val[9];
int ans[7];
int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int t;
    scanf("%d", &t);
    for(int i = 0; i<t; i++){
        
        int w;
        scanf("%d", &w);
        for(int z = 1; z<=7; z++){
            cout << z << "\n";
            cin >> val[z];
        }
        
        ans[1] = val[7] - val[6];
        ans[2] = val[2] - val[1] - ans[1];
        ans[3] = val[3] - val[2] - ans[1];
        ans[4] = val[4]- val[3] - ans[2];
        ans[5] = val[5] - val[4] - ans[1];
        ans[6] = val[6] - val[5] - ans[3] - ans[2] - ans[1];
        for(int i = 1; i<= 6; i++){
            cout << ans[i];
            if(i != 6){
                cout << " ";
            }
            
        }
        cout << "\n";
        
        memset(ans, 0, sizeof(ans));
        
        int result = 0;
        cin >> result;
        if(result == -1){
            exit(0);
        }
        
    }
    
    
}
