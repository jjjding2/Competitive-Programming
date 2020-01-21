#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

double arr[100];

int main(){
    double N;
    cin >> N;
    double x;
    cin >> x;
    double totsum = 0;
    for(int i = 0; i<N; i++){
        int n;
        cin >> n;
        arr[i] = x;
        for(int z = 0; z<n; z++){
            double temp;
            cin >> temp;
            arr[i] += temp;
        }
        totsum += arr[i];
    }
    printf("%.18f", totsum/N);
}