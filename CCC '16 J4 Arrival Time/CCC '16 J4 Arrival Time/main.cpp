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

int main(){
    string temp;
    cin >> temp;
    int x = (temp[0]-'0')*10;
    x += temp[1]-'0';
    x*= 60;
    int y = (temp[3] -'0')*10;
    y += temp[4] - '0';
    int tot = x + y;
    for(int i = 0 ;i<=240; tot ++){
        if(tot >= 7*60 && tot <= 10*60){
            i ++;
        }else if(tot >= 15*60 && tot <= 19*60){
            i ++;
        }else{
            i += 2;
        }
    }
    tot = tot % (24*60)-1;
    if(tot/60 <10){
        cout << "0";
    }
    cout << tot/60 << ":";
    if(tot % 60 < 10){
        cout << "0";
    }
    cout << tot %60;
    
}