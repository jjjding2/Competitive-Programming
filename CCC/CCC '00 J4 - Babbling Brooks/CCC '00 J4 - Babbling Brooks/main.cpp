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


vector <double> adj;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        double temp;
        scanf("%lf", &temp);
        adj.push_back(temp);
        
    }
    int t;
    scanf("%d", &t);
    while(t != 77){
        if(t == 99){ //split
            int a, p;
            scanf("%d%d", &a,&p);
            double temp = adj[a-1];
            adj.erase(adj.begin() + a-1);

            adj.insert(adj.begin() + a-1, (100-p)*0.01*temp);
            adj.insert(adj.begin() + a-1, (p)*0.01*temp);
        }else if(t == 88){   //join
            int a;
            scanf("%d", &a);
            double temp = adj[a-1] + adj[a];
            adj.erase(adj.begin() + a-1);
            adj.erase(adj.begin() + a - 1);
            adj.insert(adj.begin() + a - 1, temp);
            
        }
        scanf("%d", &t);
        
    }
    for(double j: adj){
        cout << j << " ";
        
    }
}
