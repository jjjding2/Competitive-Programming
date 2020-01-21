#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int cur = 0;
    cin >> cur;
    int sum = 0;
    while(cur != 0){
        sum += cur * 4 + 1;
        int temp = cur * cur;
        for(int i = 1; i<cur; i++){
            if(2 * i * i <= temp){
                sum += 4;
            }
        }
        for(double i = 2; i < cur; i++){
            for(double z = 1; z<i; z++){
                if(i * i + z * z <= temp){
                    sum += 8;
                }
            }
        }
        printf("%d\n", sum);
        sum = 0;
        cin >> cur;
    }
}