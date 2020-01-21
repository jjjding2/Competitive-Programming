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

priority_queue<pii,vector <pii>, greater<pii>> q [11];

int curskill [11];

int question[100001];

int skills[100001][11];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i<k; i++){
        scanf("%d", &curskill[i]);
    }
    for(int i = 0; i < n; i++){
        for(int z = 0; z<k; z++){
            
            int cur;
            scanf("%d", &cur);
            q[z].push({cur, i});
            skills[i][z] = cur;
            
        }
    }
    int ans = 0;
    while(true){
        bool work = false;
        for(int i = 0; i<k; i++){
            while(!q[i].empty() && q[i].top().first <= curskill[i]){
                question[q[i].top().second] ++;
                if(question[q[i].top().second] == k){
                    work = true;
                    ans ++;
                    for(int z = 0; z<k; z++){
                        curskill[z] +=skills[ q[i].top().second ][z];
                    }
                    question[q[i].top().second] = 0;
                }
                q[i].pop();
                
                
            }
        }
        if(!work){
            break;
        }
        
    }
    cout << ans << "\n";
    
    
    
}
