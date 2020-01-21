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
int arr[1000000];
int freq[1000000];
vector<int> adj;
int main(){
    int N;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }
    
}