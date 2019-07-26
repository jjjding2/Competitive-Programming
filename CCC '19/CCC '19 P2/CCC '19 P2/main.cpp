#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> plu;

bool prime[2000010];

bool isPrime(int num){
    bool prime = true;
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

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    
    int n;
    scanf("%d", &n);
    memset(prime, false, sizeof(prime));
    
    for (int p=2; p*p<=2000003; p++) {

        if (prime[p] == false) {

            for(int i = p*p; i<=2000003; i+= p){
                prime[i] = true;
            }
            
        }
    }
    for(int i = 0; i<n; i++){
        int a;
        scanf("%d", &a);
        if(a%2 == 0){
            for(int z = 1;z<=a; z+=2){
                int f = a - z;
                int s = a + z;
                if(!prime[f] && !prime[s]){
                    printf("%d %d\n", f, s);
                    break;
                }
            }
        }else{
        
            for(int z = 0;z<=a; z+=2){
                int f = a - z;
                int s = a + z;
                if(!prime[f] && !prime[s]){
                    printf("%d %d\n", f, s);
                    break;
                }
            }
        }
    }
}