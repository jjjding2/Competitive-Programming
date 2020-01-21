#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long double ld;
typedef long long ll;
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}

ll h[1001];
ll d[1001];
int main(){
    
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    ll n;
    cin >> n;
    for(ll i = 1; i<=n; i++){
        cin >> h[i];
    }
    for(ll i = 2; i<=n; i++){
        ll temp;
        cin >> temp;
        d[i] = d[i - 1] + temp;
        
    }
    for(ll i = 1; i<=n; i++){
        
        //l
        if(i == 1){
            cout << -1 << " ";
        }else{
            long double maxv = -1*INF;
            ll maxi = 0;
            for(ll z = i-1; z >= 1; z --){
                long double slope = ((long double)(h[z] - h[i]))/((long double)(d[i] - d[z]));
                if(slope >= maxv && h[z] > maxi){
                    maxv = slope;
                    maxi = h[z];
                }
            }
            cout << maxi << " ";
        }
        
        //r
        
        if(i == n){
            cout << -1 << " ";
        }else{
            long double maxv = -1*INF;
            ll maxi = 0;
            for(ll z = i+1; z <=n; z ++){
                long double slope = ((long double)(h[z] - h[i]))/((long double)(d[z] - d[i]));
                if(slope >= maxv && h[z] > maxi){
                    maxv = slope;
                    maxi = h[z];
                }
            }
            cout << maxi;
        }
        cout << "\n";
        
    }
    
}
