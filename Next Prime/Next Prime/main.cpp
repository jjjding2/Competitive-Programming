#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

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
    int a;
    cin >> a;
    if(a==1){
        cout << "2";
    }
    else if(a==2){
        cout << "2";
    }
    else{
        if(a%2 == 0){
            a ++;
        }
        while(true){
            if(isPrime(a)){
                cout << a;
                break;
            }
            a+=2;
    }
    }
}
