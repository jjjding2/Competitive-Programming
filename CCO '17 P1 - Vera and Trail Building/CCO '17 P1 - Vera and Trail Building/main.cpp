#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

queue <ll> cycles;

int main(){
    ll N;
    cin >> N;
    
    ll tot = 0;
    ll edge = 0;
    if(N==1){
        cycles.push(2);
        tot += 2;
        edge += 2;
    }else{
    for(ll i = N; i>0;){
        if(i*(i-1)/2 <= N){
            cycles.push(i);
            N-=i*(i-1)/2;
            tot += i;
            edge += i;
            if(N==0){
                break;
            }
        }else{
            i--;
        }
        
    }
    }
    edge += cycles.size()-1;
    
    cout << tot << " " << edge << "\n";
    
    ll counter = 1;
    
    while(!cycles.empty()){
        ll temp = cycles.front(); cycles.pop();
        ll orig = counter;
        for(int i = 0; i<temp; i++){
            if(i == temp-1){
                cout << counter << " " << orig << "\n";
            }else{
                cout << counter << " " << counter + 1 << "\n";
                counter ++;
            }
        }
        if(cycles.size()!=0){
            cout << orig << " " << counter + 1 << "\n";
            counter ++;
        }
    }
}