#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    long long ans;
    scanf("%lld", &ans);
    
    bool work = false;
    
    for(int ia = 0; ia <= 100; ia++){
        for(int ib = 0; ib <= 100; ib ++){
            for(int ic = 0; ic<= 100; ic++){
                
                if(ia*a + ib*b + ic*c == ans){
                    printf("QUEST CLEARED");
                    work = true;
                    break;
                }
                
            }
            
        }
        if(work){
            break;
        }
        
    }
    if(!work){
    printf("TRY AGAIN");
    }
    
    
    
}
