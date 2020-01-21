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

int arr[103];

bool vis[103];

queue <int> q;
queue <int> q2;


void solve(int cur, int start){
    if(cur == start){
        vis[cur] = true;
        return;
    }
    q.push(cur);
    vis[cur] = true;
    solve(arr[cur], start);
}
void solve2(int cur, int start){
    if(cur == start){
        vis[cur] = true;
        return;
    }
    q2.push(cur);
    vis[cur] = true;
    solve(arr[cur], start);
}
void swap(int a, int b){
    
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
    
}
void sim(){
    queue <int> q3 = q;
    int f = q3.front();
    int val, valn;
    valn = arr[q3.front()];
    while(!q3.empty()){
        val = valn;
        q3.pop();
        if(q3.size() == 0){
            arr[f] = val;
            break;
        }
         valn = arr[q3.front()];
        arr[q3.front()] = val;

    }
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    cin >> n;
    bool sorted = true;
    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        if(arr[i] != i){
            sorted = false;
        }
    }
    if(sorted){
        cout << 0 << "\n";
    }else{
        for(int i = 1; i<=n; i++){
            if(arr[i] == i || vis[i]){
                vis[i] = true;
            }else{
                q.push(i);
                solve(arr[i], i);
            }
            
        }
        if(q.empty()){
            cout << 0 << "\n";
            return 0;
        }else{
            sim();
            memset(vis, false, sizeof(vis));
            for(int i = 1; i<=n; i++){
                if(arr[i] == i || vis[i]){
                    vis[i] = true;
                }else{
                    q2.push(i);
                    solve2(arr[i], i);
                }
            }
            
            
            if(q2.empty()){
                cout << 1 << "\n";
                cout << q.size() << " ";
                while(!q.empty()){
                    cout << q.front() << " "; q.pop();
                }
                cout << "\n";
            }else{
                cout << 2 << "\n";
                cout << q.size() << " ";
                while(!q.empty()){
                    cout << q.front() << " "; q.pop();
                }
                cout << "\n";
                cout << q2.size() << " ";
                while(!q2.empty()){
                    cout << q2.front() << " "; q2.pop();
                }
                cout << "\n";
            }
            
        }
        
    }
    
    
    
    
}
