#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//set

int G, P; set<int> s;

int main(){
    scanf("%d %d", &G, &P);
    for(int i = 1; i<=G; i++) s.insert(i);
    for(int i = 1, x; i<=P; i++){
        scanf("%d", &x);
        auto it = s.upper_bound(x); // iterator
        if(it == s.begin()) { printf("%d\n", i-1); return 0;}
        it --; s.erase(it);
    }
    printf("%d\n", P);
}