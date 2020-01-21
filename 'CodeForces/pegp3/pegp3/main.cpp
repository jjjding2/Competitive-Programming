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

int arr[5001][5001];
int psa[5001][5001];

int main(){
    int R, C, K;
    scanf("%d%d%d", &R, &C, &K);
    for(int i = 0; i<R; i++){
        for(int z = 0; z<C; z++){
            cin >> arr[i][z];
            if(i!= 0 && arr[i][z] == 2){
                psa[i][z] = psa[i-1][z] + 1;
            }else{
                psa[i][z] = psa[i-1][z];
            }
        }
        for(int z = C; z<C + K+1; z++){
            psa[i][z] = psa[i-1][z];
        }
    }
    int sum = 0;
    for(int z = 0; z<C; z++){
        int prev = 0;
        for(int i = 0; i<R; i++){
            if(arr[i][z] == 1){
                if(psa[i+K][z] - psa[i][z] != 0){
                    sum += psa[i+K][z] - psa[i][z];
                    prev = i+K;
                    i = prev;

                }
            }
        }
    }
    cout << sum;
}