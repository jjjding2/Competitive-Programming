#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

ll fpow(ll num, ll pow){

    if(pow == 0){
        return 1;
    }else{
        ll temp = fpow(num, pow/2);
        if(pow%2 == 1){
            return temp*temp%MOD*num%MOD;
        }else{
            return (temp*temp)%MOD;
        }
    }
}


int main(){
    ll a, b;
    cin >> a >> b;
    cout << fpow(a, b) << endl;
}