#include <bits/stdc++.h>


using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define println printf("\n");
#define readln(x) getline(cin,x);
#define pb push_back
#define endl "\n"
#define MOD 1000000007
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef unordered_map<int,int> umii;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,pii> triple;
typedef int8_t byte;

ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll fpow(ll  b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}
ll divmod(ll i, ll j, ll mod){i%=mod,j%=mod;return i*fpow(j,mod-2,mod)%mod;}

int num_elements,K,low=1,high;
map<int,int> cnt;
vector<int> res;
vector<pii> v;
priority_queue<pii> q;

inline bool works(int check){
    int cnt = 0;
    for(int i=0; i<v.size(); i++){
        int rep = v[i].first/check;
        cnt+=rep;
    }
    return cnt>=K;
}

int main(){
    scanf("%d %d",&num_elements,&K);
    for(int i=1; i<=num_elements; i++){
        int n; scanf(" %d",&n);
        cnt[n]++;
    }
    for(pii check:cnt){
        q.push(mp(check.second,check.first));
        high = max(high,check.second);
    }
    while(q.size()){
        v.pb(q.top());
        q.pop();
    }
    int ans = 0;
    while(low <= high){
        int mid = (low+high)/2;
        if(works(mid)){
            ans = mid;
            low = mid+1;
        }else high = mid-1;
    }
    for(int i=0; i<K; i++){
        int rep = v[i].first/ans;
        for(int k=0; k<rep; k++){
            res.pb(v[i].second);
            if(res.size() == K) break;
        }
        if(res.size() == K) break;
    }
    for(int check:res) printf("%d ",check);
}