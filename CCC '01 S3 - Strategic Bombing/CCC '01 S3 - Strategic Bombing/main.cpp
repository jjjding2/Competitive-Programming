#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

queue <int> Q;
vector <int> adj[50];
int dis[50];

int main(){
    string input;
    cin >> input;
    while(input != "**"){
        int a = input[0]-'A';
        int b = input[1]-'A';
        adj[a].push_back(b);
        adj[b].push_back(a);
        cin >> input;
        if(input == "**"){
            break;
        }
    }
    Q.push(0);
    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        for(int i: adj[temp]){
            if(dis[i] == 0 || dis[i] > dis[temp]){
                Q.push(i);
                dis[i] = dis[temp]+1;
            }
        }
    }
    dis[0] = 0;
    int num = 0;
    for(int i = 0; i<27; i++){
        bool fail = false;
        for(int j = 0; j<27; j++){
            if(dis[i] == dis[j] && i!=j){
                fail = true;
                break;
            }
        }
        if(!fail){
            int count = 0;
            int work = 0;
            for(int z: adj[i]){
                if(dis[z] <= dis[i]){
                    work = z;
                    count ++;
                }
            }
            if(count == 1){
                char A = work + 'A';
                char B = i + 'A';
                cout << A << B << endl;
                num ++;
            }
        }
    }
    cout << "There are " << num << " disconnecting roads." << endl;
}