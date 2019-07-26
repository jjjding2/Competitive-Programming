#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int main(){
    string x;
    string op;
    string y;
    cin >> x >> op >> y;
    if(op == "*"){
        cout << "1";
        for(int i = 0; i<x.length()-1 + y.length()-1; i++){
            cout << "0";
        }
        
    }else{
        if(x == y){
            cout << "2";
            for(int i = 0; i<x.length()-1; i++){
                cout << "0";
            }
        }else{
            cout << "1";
            for(int i = 0; i<max(x.length(), y.length())-1; i++){
                int temp = abs((int)x.length() - (int)y.length());
                if(i == temp-1){
                    cout << "1";
                }else{
                    cout << "0";
                }
            }
        }
    }
}