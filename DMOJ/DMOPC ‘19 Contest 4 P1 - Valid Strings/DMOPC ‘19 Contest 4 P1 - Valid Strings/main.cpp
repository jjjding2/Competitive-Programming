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

bool balance(string a){
    int v1 = 0;
    for(int i =0 ;i<(int)a.length(); i++){
        if(a[i] == '(' ){
            v1 ++;
        }else if(a[i] == ')'){
            v1 --;
            if(v1 < 0){
                return false;
            }
        }
    }
    if(v1 == 0){
        return true;
    }else{
        return false;
    }
}

bool number(string a){
    for(int i = 0; i<(int)a.length(); i++){
        if(a[i] == '(' || a[i] == ')'){
            return false;
        }
    }
    return true;
}
bool valid(string a){
    if(a.length() == 0){
        return true;
    }
    if(number(a)){
        return true;
    }

    int val = 0;
    int start = -1;
    int end = 0;
    for(int i = 0; i<a.length(); i++){
        if(a[i] == '('){
            if(i != 0 && val == 0){
                if(!valid(a.substr(0, i)) || !valid(a.substr(i, (int)a.length() - i + 1))){
                    return false;
                }
            }
            val ++;
            if(val == 1){
                start = i;
            }
        }else if(a[i] == ')'){
            val --;
            if(val == 0 && start != -1){
                end = i;
                if(!valid(a.substr(start+1, end - start -1)) || !valid(a.substr(end + 1, a.length() - end - 1))){
                    return false;
                }
                break;
            }
            
        }

    }
    return true;
    
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        string a;
        cin >> a;
        if(!balance(a)){
            cout << "NO";
        }else{
            cout << "YES";
        }
        cout << "\n";
    }
    
}
