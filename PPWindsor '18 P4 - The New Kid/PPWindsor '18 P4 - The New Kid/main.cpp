#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

ll arrN[10000];
ll arrM[10000];

int main(){
    ll N;
    ll M;
    cin >> N >> M;
    for(int i = 0; i<N; i++){
        scanf("%lld", &arrN[i]);
    }
    for(int i = 0; i<M; i++){
        scanf("%lld", &arrM[i]);
    }
    arrM[M] = 9999999999;
    arrM[M+1] = 99999999999;

    sort(arrM, arrM + M);
    sort(arrN, arrN + N);
    ll minv = 0;
    ll mini = arrN[0];
    ll count = 0;


    for(int i = 0; i<N; i++){
        while(arrN[i]>arrM[count]){
            count ++;
        }
        ll dis;
        if(count == 0){
            dis = arrM[0] - arrN[i];
        }else{
             dis = min(abs(arrM[count - 1]-arrN[i]), abs(arrM[count]-arrN[i]));
        }
        if(arrN[i] == arrM[count]){
            dis = 0;
        }
        if(dis > minv){
            minv = dis;
            mini = arrN[i];
        }

    }
    cout << mini;
}