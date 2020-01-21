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

vector <int> adj[1000];
int arr[1001];

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 0; i<M; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 0; i<M-1; i++){
        if(abs(arr[i+1] - arr[i]) == 1){
            sum ++;
        }else{
            sum += 2;
        }
    }
    if(M == 0){
        sum -= 2;
    }
    cout << sum + 2;
}