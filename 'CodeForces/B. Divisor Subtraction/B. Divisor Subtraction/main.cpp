#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

unsigned long long cou = 0;

int main(){
    unsigned long long x;
    cin >> x;
    unsigned long long maxh = x;
    while(x!=0){
        bool work = false;

        if(x%2 == 0){
            cou += x/2;
            x = 0;
            maxh = 0;
            work = true;
        }
        for(int i = 3; i<=maxh; i+= 2){
            if(x%i == 0){
                x = x-i;
                cou ++;
                work = true;
                break;
            }else{
                maxh = (int)(x/i + 1);
            }
        }
        if(!work){
            cou ++;
            x = x - x;
            maxh = 0;
        }
    }
    cout << cou;
}