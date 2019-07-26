#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int N, M;
int arr[2000000];
vector<int>adj[200000];

bool start[2000001];

int con [2000001];
int con2 [2000001];

int main(){
    scanf("%d %d", &N, &M);
    
    for(int i = 0, temp; i<N; i++){
        scanf("%d", &temp);
        arr[i] = temp;
        

    }
    
    
    for(int i=0, u, v; i<M; i++){
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        start[v] = true;
        con[v]++;
        con2[v]++;
    }
    queue <int> Q0;
    queue <int> Q1;
    
    bool zero = false;
    bool one = false;
    
    for(int i = 0; i<N; i++){
        if(!start[i]){
            if(arr[i] == 0){
                Q0.push(i);
                zero = true;
            }else{
                Q1.push(i);
                one = true;
            }
        }
    }
    
    ll count = 0;
    int cur;
    int weap;
    
    weap = 0;

    while(!Q0.empty() || !Q1.empty()){
        
        if(weap == 0){
            while(!Q0.empty()){
                cur = Q0.front(); Q0.pop();
                for(int i: adj[cur]){
                    con[i] --;
                    if(arr[i] == weap && con[i] ==0){
                        Q0.push(i);
                    }
                    else if(arr[i] != weap && con[i] == 0){
                        Q1.push(i);
                    }
                }
            }
            weap = 1;
            count ++;
        }else if(weap == 1){
            while(!Q1.empty()){
                cur = Q1.front(); Q1.pop();
                for(int i: adj[cur]){
                    con[i] --;
                    if(arr[i] == weap  && con[i] == 0){
                        Q1.push(i);
                    }
                    else if(arr[i] != weap && con[i] == 0){
                        Q0.push(i);
                    }
                }
            }
            weap = 0;
            count ++;
        }
    }
    
    
    //
    
    for(int i = 0; i<N; i++){
        if(!start[i]){
            if(arr[i] == 0){
                Q0.push(i);
                zero = true;
            }else{
                Q1.push(i);
                one = true;
            }
        }
    }

    
    weap = 1;
    int count1 = 0;
    
    while(!Q0.empty() || !Q1.empty()){
        
        if(weap == 0){
            while(!Q0.empty()){
                cur = Q0.front(); Q0.pop();
                for(int i: adj[cur]){
                    con2[i] --;
                    if(arr[i] == weap && con2[i] ==0){
                        Q0.push(i);
                    }
                    else if(arr[i] != weap && con2[i] == 0){
                        Q1.push(i);
                    }
                }
            }
            weap = 1;
            count1 ++;
        }else if(weap == 1){
            while(!Q1.empty()){
                cur = Q1.front(); Q1.pop();
                for(int i: adj[cur]){
                    con2[i] --;
                    if(arr[i] == weap  && con2[i] == 0){
                        Q1.push(i);
                    }
                    else if(arr[i] != weap && con2[i] == 0){
                        Q0.push(i);
                    }
                }
            }
            weap = 0;
            count1 ++;
        }
    }


    
    if(count <= count1){
        cout << count-1;
    }else{
        cout << count1-1;
    }
}