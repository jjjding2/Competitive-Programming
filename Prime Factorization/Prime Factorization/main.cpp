#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int main(){
    int a;
    cin >> a;
    
    for(int i =0; i<a; i++){
        int b;
        scanf("%d", &b);
        
        while(b%2 == 0){
                b = b/2;
                cout << "2 ";
        }
        
        while(b!=1){
            bool fail = true;
                for(int z = 3; z<=sqrt(b); z+=2){
                    if(b%z == 0){
                        b = b/z;
                        cout << z << " ";
                        fail = false;
                        break;
                    }
            }
                if(fail){
                    cout << b << " ";
                    break;
                }
            
            
        }
        cout << "\n";
        }
    }

