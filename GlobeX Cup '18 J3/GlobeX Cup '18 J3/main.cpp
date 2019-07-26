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
ll fpow(ll  b, ll exp){if(exp == 0) return 1;ll t = fpow(b,exp/2);if(exp&1) return t*t*b;return t*t;}

bool isPrime(int num){
    bool prime = true;
    if(num == 1){
        return false;
    }
    if(num%2 == 0){
        prime = false;
    }else{
        for(int i = 3; i<num/2; i+=2){
            if(num%i == 0){
                prime = false;
                break;
            }
        }
    }
    return prime;
}

int digits(int num){
    int sum = 0;
    while(num!=0){
        sum += num%10;
        num = num/10;
    }
    
    return sum;
}

int main(){
    ll N;
    scanf("%lld", &N);
    ll valf = 0;
    for(int i = 0; i<N; i++){
        int x;
        scanf("%d", &x);

        if(isPrime(digits(x)) && isPrime(x)){
            valf += 1;
        }
    }
    printf("%lld", valf);
}