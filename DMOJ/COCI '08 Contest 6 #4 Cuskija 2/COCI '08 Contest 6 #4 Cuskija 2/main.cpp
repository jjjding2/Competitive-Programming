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

int arr[4];

deque <int> print;

vector <int> val[4];


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int n;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        arr[temp%3] +=1;
        val[temp%3].push_back(temp);
    }
    
    if(arr[0] == 0 && arr[1] != 0 && arr[2] != 0){
        printf("impossible\n");
        return 0;
    }else{
        
        int a = 0;
        
        while(arr[0] != 0){
            
            if(a == 2 ){
                printf("impossible\n");
                return 0;
            }else if(a == 0){
                
                print.push_back( val[0].front() );
                val[0].erase(val[0].begin());
                arr[0]--;
                a = 1;
                
            }else{
                
                if(arr[1] != 0){
                    
                    print.push_back( val[1].front() );
                    val[1].erase(val[1].begin());
                    arr[1]--;
                    a = 0;
                    
                }else if(arr[2] != 0){
                    print.push_back( val[2].front() );
                    val[2].erase(val[2].begin());
                    arr[2]--;
                    a = 0;
                }else{
                    a = 2;
                }
                
            }
            
        }
        
        while(arr[1] != 0){
            print.push_front( val[1].front() );
            val[1].erase(val[1].begin());
            arr[1]--;
        }
        while(arr[2] != 0){
            print.push_back( val[2].front() );
            val[2].erase(val[2].begin());
            arr[2]--;
        }
        
        while(!print.empty()){
            printf("%d ", print.front()); print.pop_front();
        }
        
    }
    printf("\n");
    
}
