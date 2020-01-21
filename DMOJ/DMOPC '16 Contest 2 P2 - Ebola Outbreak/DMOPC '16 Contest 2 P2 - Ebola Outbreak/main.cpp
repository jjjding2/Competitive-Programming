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
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int p[1000000];
int r[1000000];
int size[1000];


int find(int N){
    if(p[N] != N){
        p[N] = find(p[N]);
    }
    return p[N];
}


vector <int> print;
void link(int x,int y){
    if(r[x] > r[y]){
        p[y] = x;
        size[x] += size[y];

    }
    else{
        size[y] += size[x];
        p[x] = y;
        if(r[x] == r[y]){
            r[y]++;
        }
    }

}
void merge(int x, int y){
    link(find(x),find(y));
}


int main(){
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 0; i<=N; i++){
        p[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i<M; i++){
        int x;
        scanf("%d", &x);
        int start = 0;
        if(x != 0){
            scanf("%d", &start);
        }
        for(int i =1; i<x; i++){
            int temp;
            scanf("%d", &temp);
            merge(temp, start);
        }
    }
    printf("%d\n", size[find(1)]);

    for(int i = 1; i<=N; i++){
        if(find(i) == find(1)){
            printf("%d", i);
                printf(" ");
    }
    }
}