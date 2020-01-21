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

int arr[100000];

int main(){
    double N;
    cin >> N;
    double sum = 0;
    for(int i = 0; i<N; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    double avg = sum/N;
    
    int i;
    int bigger = 0;
    for(i = 0; i<N; i++){
        if(arr[i] > avg){
            bigger ++;
        }
    }
    if(bigger > (int)N/2){
        cout << "Winnie should take the risk";
    }else{
        cout << "That's too risky";
    }
    
}