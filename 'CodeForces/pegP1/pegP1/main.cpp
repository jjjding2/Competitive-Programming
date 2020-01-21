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

int main(){
    int N;
    scanf("%d", &N);
    int B;
    scanf("%d", &B);
    bool same = false;
    if(N<=59 && B<=59){
        same = true;
    }else if(N<= 69 && B<=69 && N>=60 && B >= 60){
        same = true;
    }else if(N<= 79 && B <= 79 && N >= 70 && B >= 70){
        same = true;
    }else if(N<= 89 && B <= 89 && N >= 80 && B >= 80){
        same = true;
    }else if(N >= 90&& B >= 90){
        same = true;
    }
    
    if(same){
        cout << "Same" << endl;
    }else{
        cout << "Different" << endl;
    }
    
}