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

int arr[1000];
int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
    }
    int sum = 0;
    for(int i = 0; i<N-1; i++){
        if(arr[i] == 0 && arr[i+1]!=0 && (i!=0&&arr[i-1]==1)){
            sum ++;
            arr[i+1] = 0;
        }
    }
    cout << sum << "\n";
}