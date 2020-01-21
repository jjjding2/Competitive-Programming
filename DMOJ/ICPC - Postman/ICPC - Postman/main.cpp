#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000

typedef unsigned long long ull;

typedef pair<ull, ull> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

pii pos[1001];
pii neg[1001];
unsigned long long sum = 0;

void subtract(ull i, ull k, bool add){
    if(k == 0){ return;}
    ull prev = i;
    while(pos[prev].first==0 && prev != -1){
        prev --;
    }
    if(prev == -1){return;}
    if(pos[prev].first >= k){
        if(add){
        sum +=pos[prev].first/k *pos[prev].second*2;
        }
        pos[prev].first = pos[prev].first % k;
    }else if(pos[prev].first < k){
        k = ( k-pos[prev].first);
        
        pos[prev].first = 0;
        if(add){
        sum += pos[prev].second*2;
        }
        subtract(prev, k, false);
    }else{
        if(add){
        sum += pos[prev].second*2;
        }
    }
    
}
void subtract2(ull i, ull k, bool add){
    if(k == 0){ return;}
    ull prev = i;
    while(neg[prev].first==0 && prev != -1){
        prev --;
    }
    if(prev == -1){return;}
    if(neg[prev].first >= k){
        if(add){
            sum +=neg[prev].first/k *neg[prev].second*2;
        }
        neg[prev].first = pos[prev].first % k;
    }else if(neg[prev].first < k){
        k = ( k-neg[prev].first);
        
        neg[prev].first = 0;
        if(add){
            sum += neg[prev].second*2;
        }
        subtract2(prev, k, false);
    }else{
        if(add){
            sum += neg[prev].second*2;
        }
    }
    
}

bool cmp(pii x, pii y){
    return x.second < y.second;
}

int main(){
    ull n, k;
    cin >> n >> k;
    int cpos = 0;
    int cneg = 0;
    for(int i = 0; i<n; i++){
        int x1, m1;
        cin >> x1 >> m1;
        if(x1 >= 0){
            pos[cpos] = {m1, abs(x1)};
            cpos ++;
        }else{
            neg[cneg] = {m1, abs(x1)};
            cneg ++;
        }
    }
    sort(pos, pos + cpos, cmp);
    sort(neg, neg + cneg, cmp);
    for(int i = cpos-1; i>= 0; i--){
        if(pos[i].first!=0){
            subtract(i, k, true);
        }
    }
    for(int i = cneg-1; i>= 0; i--){
        if(neg[i].first!=0){
            subtract2(i, k, true);
        }
    }

    cout << sum;
}