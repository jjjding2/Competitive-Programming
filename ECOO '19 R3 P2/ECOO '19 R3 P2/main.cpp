#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int arr[100];

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA22.txt","r",stdin);
    
    //decrease by smallest stack
    //remove pairs
    
    for(int t = 0; t<10; t++){
        int z = 0;
        cin >> z;
        for(int x = 0; x<z; x++){
            int n;
            cin >> n;
            for(int i = 0; i<n; i++){
                
                cin >> arr[i];
            }
            if(n > 4){
                cout << "A";
            }else if(n != 1){
                for(int i = 1; i<n; i++){
                    arr[i] = arr[i] - arr[0];
                }
                for(int i = 1; i<n; i++){
                    arr[i-1] = arr[i];
                }
                n --;
                
                bool good = true;
                for(int i = 0; i<n; i++){
                    if(arr[i] != 0){
                        break;
                    }
                    if(i == n - 1){
                        cout << "A";
                        good = false;
                    }
                }
                if(good){
                    if(n == 1){
                        cout << "B";
                    }
                    else if(n == 2){
                        
                        if(arr[0] == arr[1]){
                            cout << "B";
                        }else{
                            cout << "A";
                        }
                        
                    }else if(n == 3){
                        if(arr[0] == arr[1] && arr[1] == arr[2]){
                            cout << "A";
                        }else if(arr[0] == arr[1] || arr[1] == arr[2]){
                            cout << "B";
                        }else{
                            cout << "A";
                        }
                        
                    }else if(n == 4){
                        if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3]){
                            cout << "B";
                        }else if(arr[0] == arr[1] && arr[1] == arr[2]){
                            cout << "A";
                        }else if(arr[0] == arr[1] && arr[2] == arr[3]){
                            cout << "B";
                        }else if(arr[0] == arr[1]){
                            cout << "A";
                        }else{
                            cout << "A";
                        }
                        
                        
                    }
                }
                    
                
            }else{
                cout << "A";
            }
                
        }
        cout << "\n";
        
        
}
}
