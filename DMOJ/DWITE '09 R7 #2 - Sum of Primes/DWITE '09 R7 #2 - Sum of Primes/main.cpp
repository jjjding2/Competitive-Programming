#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool prime[200000];

int main(){
    for(int i = 0; i<5; i++){
        int N;
        scanf("%d", &N);
        ll sum = 0;
        for(int z = 2; z<=N; z++){
            if(!prime[z]){
                sum += z;
                for(int y = z; y<=N+z; y += z){
                    prime[y] = true;
                }

            }
        }
        memset(prime, false, sizeof(prime));
        cout << sum << endl;
    }
}