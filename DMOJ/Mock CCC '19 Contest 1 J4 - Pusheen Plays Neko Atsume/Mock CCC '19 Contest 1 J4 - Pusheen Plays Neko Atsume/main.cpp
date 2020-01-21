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

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}


struct edge{int a; string b;};

edge arr[102];

bool sortv(edge a, edge b){
    return a.a > b.a;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    arr[0].b = "aDeluxe Tuna Bitz";
    arr[1].b = "bBonito Bitz";
    arr[2].b = "cSashimi";
    arr[3].b = "dRitzy Bitz";
    
    int N;
    cin >> N;
    string ree;
    getline(cin, ree);
    for(int i = 0; i<N; i++){
        string temp;
        getline(cin, temp);
        if(temp == "Deluxe Tuna Bitz"){
            arr[0].a ++;
        }else if(temp == "Bonito Bitz"){
            arr[1].a ++;
        }else if(temp == "Sashimi"){
            arr[2].a ++;
        }else if(temp == "Ritzy Bitz"){
            arr[3].a ++;
        }
    }
    sort(arr, arr + 4, sortv);
    for(int i = 0; i<4; i++){
        if(arr[i].a != 0){
            cout << (arr[i].b).substr(1, arr[i].b.size()) << " " << arr[i].a << "\n";
        }
    }
    
    
    
}