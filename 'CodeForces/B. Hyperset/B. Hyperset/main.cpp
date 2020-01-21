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


int arr1[1510][31];

string sets[1510];

char l[4];

int n, k;
ll ans = 0;

pii groups[3][31];

void solve(pii a[3], int len){

    if(len == k+1){
        ll val = 1;
        for(int i = 0; i<3; i++){
            val *= a[i].second - a[i].first + 1;
        }
        ans += val;
    }else{
        pii temp[3][3]; // group and character
        for(int z = 0; z<3; z++){
            int spot = a[z].first;

            for(int i = 0; i<3; i++){
                 
                for(int s = a[z].second; s>= a[z].first; s--){
                    if(sets[s][len] == l[i]){
                        temp[z][i].first = spot;
                        spot = s+1;
                        temp[z][i].second = s;
                    }
                }
                 
            }
                 
        }
        for(int z = 0; z<3; z++){
            pii temp1[3];

            for(int i = 0; i<3; i++){
                temp1[i] = temp[i][z];
            }
            solve(temp1, len+1);
        }
        //all same character
        
        //all different
        pii temp1[3];
        temp1[0] = temp[0][0]; temp1[1] = temp[1][1]; temp1[2] = temp[2][2];
        solve(temp1, len+1);
        temp1[0] = temp[0][0]; temp1[1] = temp[1][2]; temp1[2] = temp[2][1];
        solve(temp1, len+1);
        temp1[0] = temp[0][1]; temp1[1] = temp[1][0]; temp1[2] = temp[2][2];
        solve(temp1, len+1);
        temp1[0] = temp[0][1]; temp1[1] = temp[1][2]; temp1[2] = temp[2][0];
        solve(temp1, len+1);
        temp1[0] = temp[0][2]; temp1[1] = temp[1][0]; temp1[2] = temp[2][1];
        solve(temp1, len+1);
        temp1[0] = temp[0][2]; temp1[1] = temp[1][1]; temp1[2] = temp[2][0];
        solve(temp1, len+1);
        
        
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    l[0] = 'E';
    l[1] = 'S';
    l[2] = 'T';
    cin >> n >> k;
    for(int i = 1; i<=n; i++){
        string a;
        cin >> a;
        sets[i] = a;

    }

    sort(sets, sets + n);
    for(int i = 1; i<=n; i++){
        cout << sets[i] << "\n";
        
    }
    pii temp1[3];
    for(int i = 0; i<3; i++){
        temp1[i].first = 1; temp1[i].second = n;
    }
    solve(temp1, 0);
    cout << ans;
}
