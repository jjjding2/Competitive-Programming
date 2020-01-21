#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

priority_queue <ll, vector <ll>, greater<ll>> q;


int main(){

    ifstream cin ("convention.in");
    ofstream cout ("convention.out");
    int N, M, C;
    cin >> N >> M >> C;
    ll maxv = 0;
    for(int i = 0; i<N; i++){
        ll temp;
        cin >> temp;
        if(temp > maxv){
            maxv = temp;
        }
        q.push(temp);
    }
    
    ll setmin = 0;
    ll val = 0;
    ll setsize = 0;
    
    bool first = true;

    ll sum = 0;
    
    while(!q.empty()){
        setmin = q.top(); q.pop();
        
        setsize += 1;
        
        while(!q.empty() && ((q.top() - setmin < maxv - q.top() && setsize < C) || M == 1)){
            setsize += 1;
            val = q.top();

            q.pop();
            if(q.empty() || q.size() == 1){
                break;
            }
            
        }
        if(val - setmin > sum){
            sum =val - setmin;
        }
        M-=1;
        setsize = 0;
        first = false;
        
    }
    
    cout << sum;
    
}