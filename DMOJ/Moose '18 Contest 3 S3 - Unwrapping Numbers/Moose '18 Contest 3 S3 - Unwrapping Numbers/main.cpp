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

ll digits(ll N){
    
    ll sum = 0;
    while(N!= 0){
        sum += N%10;
        N = N/10;
    }
    return sum;

}

queue <plu> Q;

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    ll N;
    scanf("%lld", &N);
    Q.push({N, 0});
    bool found = false;
    while(!found){
        plu temp = Q.front(); Q.pop();
        if(temp.first == 1){
            cout << temp.second << "\n";
            found = true;
        }else{
            Q.push({round( temp.first/digits(temp.first) ), temp.second + 1});
            Q.push({temp.first-1, temp.second + 1});
        }
    
    }
}