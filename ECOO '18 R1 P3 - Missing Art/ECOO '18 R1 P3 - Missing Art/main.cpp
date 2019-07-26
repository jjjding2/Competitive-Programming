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

string arr[210];

priority_queue<int, vector<int>, greater<int>>q;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA31.txt","r",stdin);
    for(int y = 0; y<10; y++){
        int n, X, Y, Z;
        cin >> n >> X >> Y >> Z;
        
        
        for(int i = 0; i<n; i++){
            string ans = "";

            string temp;
            cin >> temp;

            
            for(int spot = 0; spot < temp.length(); spot ++){
                
                int x = temp[spot] - '0';
                
                if(x == 0){
                    x = Z;
                }else if(x%2 == 0){
                    x += X;
                }else if(x%2 == 1){
                    x = max(x-Y, 0);
                }
                
                ans += to_string(x);
                
            }
            arr[i] = ans;
        }
        string A;
        cin >> A;
        bool work = true;
        for(int i = 0; i < n; i++){
            string temp;
            cin >> temp;
            if(temp != arr[i]){
                work = false;
                q.push(i + 1);
            }
        }
        string asterisk;
        cin >> asterisk;
        if(work == true){
            cout << "MATCH" << "\n";
        }else{
            cout << "FAIL: ";
            while(!q.empty()){
                cout << q.top(); q.pop();
                if(q.size()!= 0){
                    cout << ",";
                }
            }
            cout << "\n";
        }

    }
    
    
}