#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

class pairs{
public:
    int first;
    int second;
    pairs(){}
    pairs(int firsta, int seconda){
        first = firsta;
        second = seconda;
    }
    
};

class pairs2{
public:
    int first;
    int second;
    int third;
    pairs2(){}
    pairs2(int firsta, int seconda, int thirda){
        first = firsta;
        second = seconda;
        third = thirda;
    }
    
};


int arr[6];
int main(){
    int amount = 0;
    for(int a = 5; a<15; a++){
        for(int b = 4; b<=20; b++){
            for(int c = 3; c<=20; c++){
                for(int d = 2; d<=20; d++){
                    for(int e = 1; e<=20; e++){
                        if(a + b + c + d + e == 25){
                            amount ++;
                        }
                    }
                }
            }
        }
    }
    cout << amount;
}