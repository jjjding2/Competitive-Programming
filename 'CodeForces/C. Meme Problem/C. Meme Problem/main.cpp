#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }



int main(){
    int N;
    double a;
    scanf("%d", &N);
    for(int i = 0; i<N; i++){
        scanf("%lf", &a);
        if(a == 0){
            printf("Y 0.000000000 0.000000000\n");
            continue;
        }
        if(pow(a, 2) - 4*a >= 0){
            if((a + pow(pow(a, 2) - 4*a, 0.5))/2>=0 && (a - pow(pow(a, 2) - 4*a, 0.5))/2>=0){
                double print1 =(a + pow(pow(a, 2) - 4*a, 0.5))/2;
                double print2 =(a - pow(pow(a, 2) - 4*a, 0.5))/2;
                printf("Y %.10f %.10f \n", print1, print2);

            }else{
                printf("N\n");
            }
        }else{
            printf("N\n");
        }
    }
}