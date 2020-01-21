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

int a[3][3], miss[3][3], row[3], col[3], x; string s;

void solveR(int i){
    if(miss[i][0]){ a[i][0] = 2*a[i][1] - a[i][2]; miss[i][0] = 0; }
    if(miss[i][1]){ a[i][1] = 2*a[i][1] - a[i][2]; miss[i][0] = 0;}
    if(miss[i][2]){ a[i][2] = 2*a[i][1] - a[i][2]; miss[i][0] = 0;}
    row[i] --; x--;
}

void solveC(int j){
    if(miss[0][j]){a[0][j] = 2*a[1][j] - a[2][j]; miss[0][j] = 0;}
    if(miss[1][j]){ a [1][j] = (a[0][j] + a[2][j])/2; miss[1][j] = 0;}
    if(miss[2][j]){a[2][j] = 2*a[1][j] - a[0][j]; miss[2][j] = 0;}
    col[j]--; x--;
}

void fillCell(int i, int j){
    a[i][j] = 0; miss[i][j] = 0; row[i]--; col[j]--; x--;
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j<3; j++){
            cin >> s;
            if(s == "X") { miss[i][j]=1; row[i]++; col[j] ++; x++;}
            else a[i][j] = stoi(s);
        }
    }
    
    while(x > 0){
        for(int i = 0; i<3; i++)
            if(row[i] == 1) {solveR(i); goto next;}
        for(int j = 0; j<3; j++)
            if(col[j] == 1){ solveC(j); goto next;}
        for(int i = 0; i<5; i++){
            if(miss[ord[i][0]][ord[]])
        }
    }
    
    
}
