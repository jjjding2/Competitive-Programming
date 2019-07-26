#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll N, M;

vector <ll> adj[100];
ll out [100];
ll in[100];
ll innew[100];
queue <ll> Q;
double prob[100];

int main(){
    scanf("%lld %lld", &N, &M);
    for(int i = 0; i<M; i++){
        ll temp1, temp2;
        scanf("%lld %lld", &temp1, &temp2);
        temp1 --;
        temp2 --;
        adj[temp1].push_back(temp2);
        
        out[temp1] += 1;
        in[temp2] += 1;
    }
    
    Q.push(0);
    prob[0] = 1;
    while(!Q.empty()){
        ll temp = Q.front(); Q.pop();
        for(ll j: adj[temp]){
            if(innew[j] < in[j]){
                innew[j] ++;
                Q.push(j);
                prob[j] += prob[temp]/(adj[temp].size());
            }
            
        }
    }
    for(ll i = 0; i<N; i++){
        if(out[i] == 0){
            double printer = prob[i];
            if(printer == 0){
                printf("%d \n", 0);
            }else{
                printf("%.*lf \n", 12, printer);
            }
        }
    }
}