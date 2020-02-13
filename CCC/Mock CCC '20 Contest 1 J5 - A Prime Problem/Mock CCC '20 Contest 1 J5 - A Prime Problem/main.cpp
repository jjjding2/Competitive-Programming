#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll p10[1000];

bool isprime(ll a){
    if(a == 0){
        return true;
    }
    if(a%2 == 0){
        return false;
    }
    
    for(ll i = 3; i<=sqrt(a)+1; i+=2){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll d, n;
    cin >> d >> n;
    if(n == 0 && d == 0){
        cout << 2 << "\n";
        return 0;
    }
    p10[0] = 1;
    for(int i = 1; i<=100; i++){
        p10[i] = p10[i-1]*10;
    }
    ll temp = n;
    ll l = 0;
    while(temp!=0){
        temp = temp/10;
        l++;
    }

    ll best = n;
    for(ll z = n; z<= 2*p10[9]+1; z++){
        ll bruh = z;
        ll c =0;
        while(bruh != 0){
            bruh = bruh/10;
            c++;
        }
        bool good = false;
        for(ll i = 0; i<=c; i++){
            
            ll a = z%p10[d];
            ll b = z/p10[d];
            if(isprime(a) && isprime(b) && (a >= p10[d]/10) && (b >= p10[d]/10)){
                good = true;
            }
            
        }
        if(good){
            best = z;
            break;
        }
    }
    cout << best << "\n";
    
    
}
