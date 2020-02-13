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
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

string arr[100004];

vector <int> adj[100004];

pii solve(int cur, int pre, int best, string temp, int dis){
    bool good = true;
    
    bool gstart = false;
    for(int i = pre; i<min((int)arr[cur].length(), (int)temp.length()); i++){
        if(temp[i] == arr[cur][i]){
            best = cur;
            gstart = true;
        }else{
            good = false;
            break;
        }
    }
    if(gstart == true){
        
        dis ++;
    }
    int a = (int)arr[cur].length();
    int bestd = dis;
    if((int)temp.length() > a && good){
        for(int j: adj[cur]){
            pii b = solve(j, a, best, temp,dis);
            if(b.second >  bestd || (b.second == bestd && b.first < best)){
                bestd = b.second;
                best = b.first;
            }
        }
    }
    return {best,bestd};
    
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    string a;
    cin >> a;
    arr[1] = a;
    
    int n;
    cin >> n;
    int count = 2;
    for(int i = 0; i<n; i++){
        char c;
        cin >> c;
        if(c == 'C'){
            int i; string d;
            cin >> i >> d;
            arr[count] = arr[i] + d;
            adj[i].push_back(count);
            count ++;
        }else if(c == 'Q'){
            string temp;
            cin >> temp;
            cout << solve(1, 0, -1,temp,0).first << "\n";
        }
    }
}
