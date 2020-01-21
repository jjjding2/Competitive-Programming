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

bool isPrime(ll n){
    
    if(n %2 == 0){
        return false;
    }
    
    for(int i = 3; i < n/2; i+= 2){
        if(n % i == 0){
            return false;
        }
    }
    
    return true;
}

ll a, b;

bool sum2(ll n, ll first){
    
    ll temp = n/2;
    if(temp %2 == 0){
        temp -= 1;
    }
    
    for(ll i = temp; i > 0; i -= 2){
        if(i >= first && isPrime(i) && isPrime(n - i)){
            a = i;
            b = n - i;
            return true;
        }
    }
    return false;

}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll num;
    
    for(int z = 0; z<5; z++){
        scanf("%lld", &num);
        printf("%lld", num);
        printf(" = ");
        if(num % 2 == 0){
            if(sum2(num, -1) == true){
                printf("%lld", a);
                printf(" + ");

                printf("%lld", b);

                printf("\n");
            }
        }else{
            if(isPrime(num)){
                printf("%lld", num);
                printf("\n");
            }else{
                ll temp = num/3;
                if(temp % 2 == 0){
                    temp = temp - 1;
                }
                for(ll i = temp; i>0; i -= 2){
                    if(isPrime(i)){
                        if(sum2(num - i, i) == true){
                            printf("%lld", i);
                            printf(" + ");
                            printf("%lld", a);
                            printf(" + ");
                            printf("%lld", b);

                            printf("\n");

                            break;
                        }
                    }
                }
                
            }
        
        }
        
        
    }
    
}