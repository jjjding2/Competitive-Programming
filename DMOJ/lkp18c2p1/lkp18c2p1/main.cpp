#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int arr[1001];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    for(int i = 0; i<m; i++){
        cout << arr[0] << "\n";
        arr[0] += 1;
        sort(arr, arr + n);
    }
    
}