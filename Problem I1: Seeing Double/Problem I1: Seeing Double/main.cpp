#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<string,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

umii mymap;

int main(){
    int N;
    scanf("%d", &N);
    int sum = 0;
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
            mymap.emplace(temp, 10);
        
    }
    
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        if(mymap.count(temp) > 0){
            sum ++;
        }
    }
    cout << sum;
    
}