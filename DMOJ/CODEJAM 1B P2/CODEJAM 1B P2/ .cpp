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
typedef pair<char, pair<int, int>> pii;
typedef pair<int, int> pi;

typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

vector <pii> adj[4];


int arrx1[100003];

int arrx2[100003];

int arry1[100003];

int arry2[100003];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int t;
    cin >> t;
    for(int z = 0; z<t; z++){
        int n, q;
        cin >> n >> q;
        
        for(int i = 0; i<n; i++){
            int a, b;
            char d;
            cin >> a >> b >> d;
            if(d == 'N'){
                adj[0].push_back({d,{a, b}});
            }else if(d == 'E'){
                adj[1].push_back({d,{a, b}});
            }else if(d == 'S'){
                adj[2].push_back({d,{a, b}});
            }else if(d == 'W'){
                adj[3].push_back({d,{a, b}});
            }
            
        }
        pi ans = {0, 0};

        for(pii x: adj[0]){ //N
                arry1[x.second.second+1]++;
            
        }
    
        for(pii x: adj[2]){
                arry2[x.second.second-1] ++;
            
        }
        
        for(int i = 0; i < q; i++){
            arry1[i+1] += arry1[i];
        }
        
        for(int i = q; i > 0; i--){
            arry2[i-1] += arry2[i];
            arry2[i] += arry1[i];
        }
        //
        for(pii x: adj[1]){
            
            arrx1[x.second.first+1] ++;
            
        }
        for(pii x: adj[3]){
            
            arrx2[x.second.first - 1] ++;
        }
        for(int i = 0; i<q; i++){
            arrx1[i+1] += arrx1[i];
        }
        for(int i = q; i>0; i--){
            arrx2[i-1] += arrx2[i];
            arrx2[i] += arrx1[i];
        }
        int maxv = 0;
        for(int i = 0; i<=q; i ++){
            if(arrx2[i] > maxv){
                maxv = arrx2[i];
                ans.first = i;
            }
        }
        maxv = 0;
        for(int i = 0; i<=q; i ++){
            if(arry2[i] > maxv){
                maxv = arry2[i];
                ans.second = i;
            }
        }
        
            
        
        cout << "Case #" << z+1 << ": " << ans.first << " " << ans.second << "\n";
        
        memset(arry1, 0, sizeof(arry1));
        memset(arry2, 0, sizeof(arry2));
        memset(arrx1, 0, sizeof(arrx1));
        memset(arrx2, 0, sizeof(arrx2));
        
        adj[0].clear();
        adj[1].clear();
        adj[2].clear();
        adj[3].clear();
    }
    
    
}
