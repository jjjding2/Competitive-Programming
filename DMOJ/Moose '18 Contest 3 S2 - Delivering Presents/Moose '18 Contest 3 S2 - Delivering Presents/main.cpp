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

pii start[5001];

bool tdone[5001];
bool cmpB(pii a, pii b){
    return a.second < b.second;
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    int N;
    scanf("%d", &N);
    int sum = 0;

    for(int i = 0; i<N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        
        start[i] = {a, b};
        
    }
    sort(start, start + N, cmpB);
    
    for(int i = 0; i<N; i++){
        if(start[i].first <= i+1 && start[i].second > i + 1){
            sum ++;
        }
    }
    printf("%d", sum);
    
    
}