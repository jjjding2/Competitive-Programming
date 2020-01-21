#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

int n;pair<long double,long double> arr[5001];

pair<long double,long double> eq(long double x1,long double y1,long double x2,long double y2){
    long double m = (y1-y2)/(x1-x2);
    long double b = y1-m*x1;
    return {m,b};
}
long double dist(long double x1,long double y1,long double x2,long double y2){
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
pair<long double,long double> inter(pair<long double,long double> eq1, pair<long double,long double> eq2,pair<long double,long double> t1, pair<long double,long double> t2,bool c1,bool c2){
    long double x = (eq1.second-eq2.second)/(eq1.first-eq2.first);
    if(c1){
        return {t1.first,eq1.first*t1.first+eq1.second};
    }
    if(c2){
        return {t2.first,eq2.first*t2.first+eq2.second};
    }
    return {x,eq1.first*x+eq1.second};
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    freopen("DATA21.txt","r",stdin);
    for(int z = 0;z<10;z++){
        cin >> n;int ans = 0;
        for(int i = 0;i<n;i++){
            cin >> arr[i].first >> arr[i].second;
        }
        for(int i = 0;i<n/2;i++){
            pair<long double,long double> equation = eq(arr[i].first,arr[i].second,arr[i+n/2].first,arr[i+n/2].second);
            bool c = 0;
            int p1 = i+1,p2 = i-1;
            while(p1 != p2){
                if(p1 == i || p1 == i+n/2){
                    p1++;
                }
                if(p2 == i || p2 == i+n/2){
                    p2--;
                }
                if(p1 == n){
                    p1 = 0;
                }
                if(p2 == -1){
                    p2 = n-1;
                }
                if(p1 == i || p1 == i+n/2){
                    p1++;
                }
                if(p2 == i || p2 == i+n/2){
                    p2--;
                }
                pair<long double,long double> check = eq(arr[p1].first,arr[p1].second,arr[p2].first,arr[p2].second);
                pair<long double, long double> point = inter(equation,check,arr[i],arr[p1],arr[i].first == arr[i+n/2].first,arr[p1].first == arr[p2].first);
                if((long double)((-1)/check.first != equation.first) && !(check.first == 0 && arr[i].first == arr[i+n/2].first) && !(arr[p1].first == arr[p2].first && equation.first == 0)){
                    if(dist(point.first,point.second,arr[p1].first,arr[p1].second) != dist(point.first,point.second,arr[p2].first,arr[p2].second)){
                        c = 1;
                        break;
                    }
                }
                p2--;p1++;
            }
            if(!c){ans++;}
        }
        cout << ans << "\n";
    }
}
