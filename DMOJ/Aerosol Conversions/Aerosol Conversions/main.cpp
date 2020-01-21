#include <bits/stdc++.h>

using namespace std;

int main(){
    long double map = 2e16/5;
    long double maxp = 1.5e6;
    long double ratio = maxp/4.5;
    
    while(true){
        long double temp;
        scanf("%Lf",&temp);
        printf("%Lf\n", temp*map*ratio);
    }
}
