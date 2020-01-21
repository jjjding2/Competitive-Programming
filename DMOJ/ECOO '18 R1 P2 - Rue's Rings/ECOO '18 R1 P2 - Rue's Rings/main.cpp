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

queue <int> q[70001];
int idv[70001];

priority_queue<int, vector<int>, greater<int>> ans;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    for(int y = 0; y<10; y++){
        int n;
        cin >> n;
        int minv = INF;
        int id;
        int num = 0;
        for(int i = 0 ; i < n ; i++){

            cin >> id >> num;
            idv[i] = id;
            for(int x = 0; x<num; x++){
                int temp;
                cin >> temp;
                if(temp < minv){
                    minv = temp;
                }
                q[i].push(temp);
            }
        }
        cout << minv << " {";
        for(int i = 0; i<n; i++){
            bool done = false;
            while(!q[i].empty()){
                if(q[i].front() == minv && !done){
                    done = true;
                        ans.push(idv[i]);

                }
                q[i].pop();
            }
        }
        if(ans.empty()){
            cout << "}" << "\n";
        }
        while(!ans.empty()){
            if(ans.size()!=1){
                cout << ans.top() << ",";
            }else{
                cout << ans.top() << "}" << "\n";
            }
            ans.pop();
        }

    }
    
}