#include <bits/stdc++.h>
typedef unsigned long long ull;

using namespace std;

double arr[1000][2];

int main() {
    int N;
    scanf("%d", &N);
    double cursum = 0;
    for(int i = 0; i<N; i++){
        scanf("%lf", &arr[i][0]);
    }
    for(int i = 0; i<N; i++){
        scanf("%lf", &arr[i][1]);
    }
    for(int i = 0; i<N; i++){
        cursum += abs(arr[i][0] - arr[i][1]) * abs(arr[i][0] - arr[i][1]);
    }
    
    printf("%.18f", pow(cursum, 0.5));
}