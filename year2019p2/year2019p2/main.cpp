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



int dis[100001];
int endv = 0;
int start = 0;
int p[100001];
int N, M;
pii j;
void parent(int cur){
    if(p[cur] == -1 || cur == start){
        printf("%d ", cur);

        return;
    }
    parent(p[cur]);
    
    if(p[cur] == -1){
        printf("%d ", cur);
    }else if(cur == endv){
        printf("%d", cur);
    }else{
        printf("%d", cur);
        printf("\n%d ", cur);
    }
    
    
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    scanf("%d%d", &N, &M);
    
    
    for(int i = 0; i<M; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(i == 0){
            start = a;
            memset(dis, INF, sizeof(dis));
            dis[start] = 0;
            p[start] = -1;
        }else if(i == M-1){
            endv = b;
        }
        int temp = a;
        j = {b, i+1};
        if(dis[j.first] > dis[temp] + 1 && j.first != temp){
            dis[j.first] = dis[temp] + 1;
            p[j.first] = temp;
        }
    }
    
    printf("%d\n", dis[endv]);
    p[start] = -1;
    parent(endv);
    
}






