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

int arr[3];
int size[3];

int main(){
    ifstream fin ("mixmilk.in");
    ofstream fout ("mixmilk.out");
    for(int i =0; i<3; i++){
        cin >> size[i];
        cin >> arr[i];
    }
    int curspot = 0;
    for(int i = 0; i<4; i++){
        int f = (curspot + 1)%3;

        int temp = arr[f];
        arr[f] = min(size[f], arr[curspot] + arr[f]);
        arr[curspot] -= arr[f] - temp;
        curspot += 1;
        curspot = curspot%3;
    }
    for(int i = 0; i<3; i++){
        cout << arr[i] << "\n";
    }
}