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

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int N;
    scanf("%d", &N);
    
    for(int i = 0; i<N-1; i++){
        cout << "#";
    }
    cout << "." << "\n";
    for(int z = 0; z<N-2; z++){
        cout << "#";
        for(int i = 0; i<N-2; i++){
            cout << ".";
        }
        cout << "#" << "\n";
    }
    
    for(int i = 0; i<N-1; i++){
        cout << "#";
    }
    cout << "." << "\n";
    
    for(int z = 1; z<=N-1; z++){
        
        cout << "#";
        for(int i = 1; i<z; i++){
            cout << ".";
        }
        cout << "#";
        for(int i = 0; i<N - z-1; i++){
            cout << ".";
        }
        cout << "\n";
        
    }
    
    
    
}