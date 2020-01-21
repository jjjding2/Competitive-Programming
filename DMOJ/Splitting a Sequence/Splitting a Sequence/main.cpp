#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

#define maxx pow(2, 31)-1

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ ll first,second; };

vector <ll> arr;

ll N, M, temp;


bool check(vector <ll> adj, ll maxv){
    ll sum = 0;
    ll count = 1;
    for(int i = 0; i<(int)adj.size(); i++){
        if(adj[i] + sum > maxv){
            count ++;
            sum = adj[i];
        }else{
            sum += adj[i];
        }
    }
    if(count <= M){
        return true;
    }else{
        return false;
    }
}

int main(){
    scanf("%lld %lld", &N, &M);
    ll start = 0;
    ll end = 0;
    for(int i = 0; i<N; i++){
        scanf("%lld", &temp);
        arr.push_back(temp);
        if(temp > start){
            start = temp;
        }
        end += temp;
    }
    
    ll mid = end;
    ll ans = end;
    while(start <= end){
        mid = (start + end)/2;
        if(check(arr, mid)){
            end = mid-1;
            ans = mid;
        }else{
            start = mid + 1;
        }
    }
    printf("%lld\n", ans);
}