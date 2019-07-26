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


vector <pii> adj[1000001];



bool pew[1000001][101];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ll N, M;
    scan(N);
    scan(M);
    
    
    for(int i = 1; i<=N; i++){
        int a, b;
        scan(a);
        scan(b);
        adj[i].push_back({a, 0});
        adj[i].push_back({b, 1});
    }
    
    ll zero = N;
    
    ll count = M;

    for(int i = 1; i<=count; i++){
        for(int z = 1; z<=N; z++){
            pew[z][i] = pew[z][i-1];
        }
        int cur = 1;
        while(cur != N + 1){
            for(pii j: adj[cur]){
                if(j.second == pew[cur][i]){
                    if(pew[cur][i] == 0){
                        pew[cur][i] = 1;
                        zero --;
                    }else{
                        pew[cur][i] = 0;
                        zero ++;
                    }
                    cur = j.first;
                    break;
                }
            }
        }
        

            for(int z = 1; z<=N; z++){
                printf("%d", pew[z][i]);
            }
            printf("\n");
            break;
        


        
        
    }
    
    
    
}