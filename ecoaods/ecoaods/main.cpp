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

priority_queue<int, vector<int>, greater<int>>q;

string arr[500000];
string first[500000];
string last[500000];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA21.txt","r",stdin);
    
    for(int y = 0; y<10; y++){
        int rule, n;
        cin >> rule >> n;
        string start;
        cin >> start;
        
        for(int i = 0; i<rule; i++){
            string a;
            cin >> a;
            
            string b;
            cin >> b;
            arr[(int)a[0]] = b;
            
        }
        
        for(int i = 0; i<n; i++){
            string newv = "";
            for(int z = 0; z<start.length(); z++){
                newv += arr[(int)start[z]];
            }
            start = newv;
            
        }
        cout << start[0] << start[start.length()-1] << " " << start.length() << "\n";
        memset(arr, 0, sizeof(arr));
    }
    
    
}