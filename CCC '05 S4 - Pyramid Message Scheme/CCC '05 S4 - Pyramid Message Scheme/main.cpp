#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<string,int> umii;

class pairs{
public:
    int first;
    int second;
    pairs(){}
    pairs(int f, int s){
        first = f;
        second = s;
    }
};

string arr[100];
int N;
vector <int> adj[100];

queue <int > Q;

int dis[100];
int main(){
    
    int L;
    scanf("%d", &L);
    for(int i = 0; i<L; i++){
        umii name;
        scanf("%d", &N);
        for(int z = 0; z<N; z++){
            cin >> arr[z];
            name.emplace(arr[z], z);
        }
        int maxv = 0;
        int cur;
        if(N == 1){
            cout << 0 << endl;
        }else{
             cur = name[arr[N-1]];
            int curo = cur;
            for(int z = 0; z<N; z++){
                adj[curo].push_back(name[arr[z]]);
                curo = name[arr[z]];
            }
            Q.push(cur);
            while(!Q.empty()){
                int temp = Q.front(); Q.pop();
                for(int j:adj[temp]){
                    if(dis[j] == 0 || dis[j]>dis[temp]+1){
                        dis[j] = dis[temp]+1;
                        Q.push(j);
                    }
                }
                
            }
        }
        for(int z = 0; z<100; z++){
            if(dis[z] > maxv && z != cur){
                maxv = dis[z];
            }
            arr[z] = "";
            name.clear();
            dis[z] = 0;
            adj[z].clear();
        }
        cout << N*10  - maxv*20 << endl;
    }}