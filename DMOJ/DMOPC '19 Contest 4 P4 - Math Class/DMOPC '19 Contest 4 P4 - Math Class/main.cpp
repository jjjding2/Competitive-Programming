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
typedef pair<ll, ll> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

pii arr[1000];

int n;
ll ax, ay;
ll bx, by;
bool check(ll vx, ll vy){
    if((fpow(abs(vx - ax)%MOD, 2, MOD) + fpow(abs(vy - ay)%MOD,2, MOD))%MOD == (fpow(abs(vx - bx)%MOD, 2, MOD) + fpow(abs(vy - by)%MOD,2, MOD))%MOD){
        return true;
    }else{
        return false;
    }
}

ll dis(ll ax, ll ay, ll bx, ll by){
    return (fpow(abs(bx - ax)%MOD, 2, MOD)%MOD + fpow(abs(by - ay)%MOD,2, MOD)%MOD)%MOD;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);

    cin >> n >> ax >> ay >> bx >> by;

    for(int i = 0; i<n; i++){
        ll vx, vy;
        cin >> vx >> vy;
        arr[i] = {vx, vy};
    }
    
    
    if(ax == bx && ay == by){
        cout << 0;
    }else{
        ll dis1 = 0;
        ll dis2 = 0;
        ll dis1a = 0;
        ll dis2a = 0;
        ll dis3 = 99;
        if(n == 2){
            dis1 = dis(arr[0].first, arr[0].second, ax, ay);
            dis2 = dis(arr[1].first, arr[1].second, bx, by);
            dis1a = dis(arr[0].first, arr[0].second, bx, by);
            dis2a = dis(arr[1].first, arr[1].second, ax, ay);
            
            dis3 = dis(arr[1].first, arr[1].second, arr[0].first, arr[1].second);
            cout << dis1 << " " << dis2 << " " << dis3 << "\n";

        }
        if(check(arr[0].first, arr[0].second)){
            cout << 1;
        }else if(check(arr[1].first, arr[1].second)){
            cout << 1;
        }else if(n == 2 && pow((double)dis1, 0.5) + (double)pow((double)dis2,0.5)) <= pow((double)dis3, 0.5){
            cout << 2;
        }
        else{
            cout << -1;
        }
        
    }
    
}
