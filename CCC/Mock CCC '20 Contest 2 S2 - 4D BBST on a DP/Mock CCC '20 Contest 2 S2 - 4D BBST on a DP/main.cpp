#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

deque <char> q;

int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    string temp;
    cin >> temp;
    int l = INT_MAX;
    for(int i = 0; i<n; i++){
        if((int)temp[i] <= l){
            l = (int)temp[i];
            q.push_front(temp[i]);
        }else{
            q.push_back(temp[i]);
        }
    }
    while(!q.empty()){
        cout << q.front(); q.pop_front();
    }
}
