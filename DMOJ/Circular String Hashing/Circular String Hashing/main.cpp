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
typedef unordered_map<string, bool> umii;

umii temp;
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


set <ll> start;

ll pw[50001];

void init(){
    
    pw[0] = 1;
    for(ll i = 1; i<= 50001; i++){
        pw[i] = pw[i - 1]*131;
    }
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll n;
    cin >> n;
    string temp;
    cin >> temp;
    
    temp = temp + temp;
    string temp2 = "";
    for(int i = (int)temp.length() - 1; i>=0; i--){
        temp2 += temp[i];
    }
    temp2 += temp2;
    
    
    ll c = 0;
    ull cheese = 0;
    
    int cheesenumber = 30;
    
    ll cur = 0;
    ll cur2 = 0;
    for(int z = 0; z <= n; z++){

        for(int i = 0; i<=min(cheesenumber, (int)n); i++){
            cur += pw[i]*temp[i + z];
            cur2 = cur2*131 + temp[i + z];
            start.insert(cur);
            start.insert(cur2);
            
            c += 2;
        }
    }
    cheese += start.size();

    if(cheesenumber < n){
        cheese += 2*n * (n - cheesenumber);
        
        if(cheesenumber == 0){
            cheese -= n;
        }
        
    }
    
    cout <<  cheese << "\n";
    
}
