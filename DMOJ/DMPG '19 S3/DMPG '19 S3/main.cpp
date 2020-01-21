#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
#define MOD 1000000007

typedef unsigned long long ll;


map<string,ll> ans;

vector <string> adj;

stack <string> s;

deque <ll> cur;

deque <ll> ele;

deque <ll> bracket;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i<n; i++){
        string temp;
        cin >> temp;
        if(temp[0] == '('){
            s.push(temp);
        }else if(temp[0] == ')'){
            s.push(temp);
            ll temp2;
            cin >> temp2;
            bracket.push_back(temp2);
        }else{
            if(ans.count(temp) == 0){
                ans.emplace(temp, 0);
                adj.push_back(temp);
                
            }
            s.push(temp);
            ll temp2;
            cin >> temp2;
            
            ele.push_back(temp2);
        }
        
    }
    
    unsigned long long factor = 1;
    while(!s.empty() || !cur.empty() || !bracket.empty()){
        string temp = s.top(); s.pop();
        if(temp[0] == ')'){
            cur.push_back(factor);

            factor = (factor%MOD * bracket.back()%MOD)%MOD;
            bracket.pop_back();
        }else if(temp[0] == '('){
            if(cur.back() != 0){
                factor = cur.back()%MOD; cur.pop_back();
            }
            
        }else{
            ans[temp] = (ans[temp]%MOD + (( ele.back()%MOD )*(factor%MOD))%MOD)%MOD;
            ele.pop_back();
        }
    }
    sort(adj.begin(), adj.end());
    for(string j: adj){
        cout << j << " " << ans[j]%MOD << "\n";

    }

}
