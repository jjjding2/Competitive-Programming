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

bool super[100];

ll dis[100];

vector <pii> adj[100];

queue <int> Q;

int ar[3][2000001];

int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    for(int i = 0; i<K; i++){
        int temp;
        scanf("%d", &temp);
        super[temp] = true;
    }
    int newv = N + 1;
    for(int i = 1; i<=N-1; i++){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        ar[0][i] = a;
        ar[1][i] = b;
        ar[2][i] = c;
        adj[a].push_back({b, c});


    }
    for(int i = 1; i<=N-1; i++)
    {
        if(super[i] == true){
            adj[ar[1][i]].push_back({newv, ar[2][i]});
            for(pii j: adj[ar[0][i]]){
                if(j.first != ar[1][i]){
                    adj[newv].push_back(j);
                }
            }
            newv += 1;
        }
    }
    Q.push(1);
    ll maxv = 0;
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(pii j: adj[temp]){
            if(dis[temp] + j.second > dis[j.first]){
                dis[j.first] = dis[temp] + j.second;
                if(dis[j.first]> maxv){
                    maxv = dis[j.first];
                }
                Q.push(j.first);
            }
        }
    }
    printf("%lld", maxv);
}