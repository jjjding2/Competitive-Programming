#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, double> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<string,int> umii;

umii maps;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <pii> adj[5000];

double dis[5001];

queue <pii> q;

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    cin.tie(0); cin.sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    int s = 0;
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        if(temp == "APPLES"){
            s = i;
        }
        maps.emplace(temp, i);
        dis[i] = 0;
    }
    for(int i = 0; i<M; i++){
        string a, b;
        cin >> a >> b;
        double num;
        cin >> num;
        adj[maps.at(a)].push_back({maps.at(b), num});
    }
    dis[s] = 1;
    q.push({s, 1});
    while(!q.empty()){
        pii temp = q.front(); q.pop();
        
        for(pii j: adj[temp.first]){
            if(dis[j.first] < temp.second*j.second){
                dis[j.first] = temp.second*j.second;
                q.push({j.first, dis[j.first]});
                if(j.first == s && dis[j.first] > 1){
                    cout << "YA";
                    return 0;
                }
            }
            
        }
    }
    
    

        cout << "NAW";
    
    
}