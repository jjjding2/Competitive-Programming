#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };


ll val[100002];
vector <ll> Q1;
vector <ll> Q2;

vector <ll> adj[10000];
bool vis[100001];


ll freq[100];

bool work;

void dfs(ll cur, ll pre, vector <ll> Q, ll n2){

    for(ll j: adj[cur]){
        if(j==pre){
            continue;
        }else if(vis[j]==false){
            vis[j] = true;
            Q.push_back(val[j]);
            dfs(j, cur, Q, n2);
            Q.pop_back();
        }
        
    }
    if(cur == n2 && work == false){
        work = true;
        while(!Q.empty()){
            Q2.push_back(Q.front());
            Q.erase(Q.begin());
        }
    }
}

int main(){
    int N, q;
    scanf("%d %d", &N, &q);
    for(int i = 1; i<=N; i++){
        int temp;
        scanf("%d", &temp);
        val[i] = temp;
    }
    for(int i = 0; i<N-1; i++){
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        adj[x1].push_back(x2);
        adj[x2].push_back(x1);
    }
    for(int i = 0; i<q; i++){
        int type, n1, n2;
        scanf("%d %d %d", &type, &n1, &n2);
        
        Q1.push_back(val[n1]);
        vis[n1] = true;
        work = false;
        dfs(n1, -1, Q1, n2);
        Q1.clear();
        if(type == 1){
            int L = (int)Q2.size();
            long long sum = 0;
            while(!Q2.empty()){
                sum += Q2.front();
                Q2.erase(Q2.begin());
            }
            
            //ll xx = round(sum/L);
            ll xx = (ll)((double)sum/L + 0.5);
            printf("%lld \n", xx);
        }else if(type == 2){
            int size = (int)Q2.size();
            ll times = (int)size/2;
            if((int)size%2 != 1){
                times --;
            }
            for(int z = 0; z<times; z++){
                Q2.erase(Q2.begin());
            }
            if((int)size%2 == 1){
                printf("%lld \n", Q2.front());
            }else{
                double x = Q2.front();
                Q2.erase(Q2.begin());
                double y = Q2.front();
                //ll xx = round((x + y)/2);
                ll xx = (ll)((x+y)/2 + 0.5);
                printf("%lld \n", xx);
            }
            Q2.clear();
        }else if(type == 3){
                int count = 0;
                int l = (int)Q2.size();
                while(!Q2.empty()){
                    freq[count] = Q2.front();
                    Q2.erase(Q2.begin());
                    count ++;
                }
                sort(freq, freq + l);
                ll counter = 1;
                ll maxv = 1;
                ll maxi = freq[0];
                for(int z = 1; z<l; z++){
                    
                    if(freq[z-1] == freq[z]){
                        counter ++;
                    }else{
                        counter = 1;
                    }
                    
                    if(counter > maxv || (counter == maxv && maxi>freq[z])){
                        maxv = counter;
                        maxi = freq[z];
                    }
            }
            printf("%lld \n", maxi);
        }
        memset(vis, false, sizeof(vis));
        memset(freq, 0, sizeof(freq));
        Q1.clear();
        Q2.clear();
    }
    
}