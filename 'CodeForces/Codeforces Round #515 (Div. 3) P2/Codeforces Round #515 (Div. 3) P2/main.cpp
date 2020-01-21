#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pii;
//{v, w}
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


ll arr[1000005];
vector <ll> adj;

int main(){
    ll N;
    cin >> N;
    ll sum = 0;
    if(N == 1){
        cout << 0 << "\n";
        return 0;
    }
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(N == 2){
        if(arr[0] == arr[1]){
            cout << "2" << "\n";
            cout << "1" << " " << "2";
        }else{
            cout << 0 << "\n";
        }
        return 0;
    }
    ll maxv = 0;
    ll maxi = -1;
    ll maxv2 = 0;
    for(int i = 0; i<N; i++){
        if(arr[i] > maxv){
            maxv = arr[i];
            maxi = i;
        }
    }
    for(int i=0; i<N; i++){
        if(arr[i]>maxv2 && (arr[i]!=maxv||i!=maxi)){
            maxv2 = arr[i];
        }
    }

    for(int i = 0; i<N; i++){
        if(arr[i] == maxv){
            if(sum - maxv - maxv2 == maxv2){
                adj.push_back(i +1);
            }
        }else if(sum - arr[i] - maxv == maxv){
            adj.push_back(i+1);
        }
    }
    cout << adj.size() << "\n";
    while(!adj.empty()){
        ll temp = adj.back();
        cout << temp << " ";
        adj.pop_back();
    }
}