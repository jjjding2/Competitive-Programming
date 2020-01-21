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

ll friends [1000008];

ll val[1000008];
int type;
int friendv;
ll a, b, c;

int main(){
    ll N, Q;
    scanf("%lld%lld", &N, &Q);
    for(int i = 1; i<=N; i++){
        scanf("%lld", &friends[i]);
    }
    for(int i = 0; i<Q; i++){
        scanf("%d", &type);
        if(type == 2){
            scanf("%d", &friendv);
            printf("%lld\n", val[friendv]);
        }else{
            scanf("%lld%lld%lld", &a, &b, &c);
            
            ll lower = 1;
            ll higher = N;
            ll mid = (lower + higher)/2;
            while(lower <= higher){
                mid = (lower + higher)/2;
                if(friends[mid] == min(a, b)){
                    break;
                }
                else if(friends[mid] > min(a, b)){
                    higher = mid-1;
                }else{
                    lower = mid + 1;
                }
            }
            if(friends[mid] < a){
                mid ++;
            }
            
            
             lower = 1;
             higher = N;
            ll mid2 = (lower + higher)/2;
            while(lower <= higher|| friends[mid] > b){
                mid2 = (lower + higher)/2;
                if(friends[mid2] == max(a, b)){
                    break;
                }
                else if(friends[mid2] > max(a, b)){
                    higher = mid2-1;
                }else{
                    lower = mid2 + 1;
                }
            }
            if(friends[mid2] > b){
                mid2 --;
            }
            for(ll z = mid; z<= mid2; z++){
                val[z] += c;
            }
            
        }
    }
}