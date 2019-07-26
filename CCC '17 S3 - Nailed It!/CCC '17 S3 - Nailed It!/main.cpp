#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll length[2001];
ll sum[4002];

int main(){
    int N;
    scanf("%d", &N);
    for(int i = 1; i<=N; i++)
    {
        int spot;
        scanf("%d", &spot);
        length [spot] ++;
    }
    
    for(int i = 1; i<=2000; i++){
        if(length[i]!= 0){
            for(int j = i; j<=2000; j++){
                if(i == j){
                    sum[i + j] += (int)length[i]/2;
                } else if(length[j]!=0){
                    sum[i + j] += min(length[i],length[j]);
                }
                    
        }
    }
        
        
    }
    ll big = 0;
    ll num = 1;
    for(int i = 0; i<4000; i++){
        if(sum[i]>big){
            big = sum[i];
            num = 1;
        }else if(sum[i]==big){
            num ++;
        }
    }
    cout << big << " " << num;
}