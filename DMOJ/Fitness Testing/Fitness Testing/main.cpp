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

ll arr[1000000];
ll L1, G1;
void gen(){
    srand(time(NULL));
    ll temp = rand()%100000 + 1;
    cout << temp << "\n";
    string fin = "";
    ll sum = 0;
    for(int i = 0; i<temp; i++){
        ll asdf = rand()%100000;
        arr[i] = asdf;
        sum += asdf;
        cout << asdf << " ";
    }
    
    ll L = sum + 10;
    while(L >= sum+10){
        L = rand()%100000000 +arr[0];
    }
    L1 = L;
    ll G = L;
    while(G >= L){
        G = rand()%100000000 +arr[0];
    }
    G1 = G;
    cout << "\n" << L << " " << G;
}

int main(){
    gen();
    int index = -1;
    while(L1 >= 0){
        index ++;
        L1 -= arr[index];
    }
    sort(arr, arr + index);

    int i = 0;
    for(i = 0; i<index; i++){
        G1 = G1 - arr[i];
        if(G1 < 0){
            break;
        }
    }
    cerr << " " <<index - i;
}