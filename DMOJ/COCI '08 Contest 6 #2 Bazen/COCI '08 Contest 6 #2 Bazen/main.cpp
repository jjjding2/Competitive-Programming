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

double edge(double x){
    return 250 - x;
    
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    double x, y;
    scanf("%lf%lf", &x, &y);
    double ans = 250*250/2;
    bool alt = false;

    if((x == 0 && y != 250) || (y == 0&& x != 250)){
        if(y == 0){
            alt = true;
        }
        y += x;
        x = 0;
        if(y > 125){
            
            double xcoord = ans/y;
            xcoord = abs(round(xcoord*100)/100);
            
            if(!alt){
                printf("%.2f %.2f", xcoord, 0.00);
                
            }else{
                printf("%.2f %.2f", 0.00, xcoord);
            }

        }else{
        double xcoord = ans/(250.00 - y);
        xcoord = abs(round(xcoord*100)/100);
        double ycoord = abs(round(edge(abs(xcoord))*100)/100);
        if(alt){
            printf("%.2f %.2f", ycoord, xcoord);

        }else{
        printf("%.2f %.2f", xcoord, ycoord);
        }
        }
    }else{
        if(x < y){
            int temp = y;
            y = x;
            x = temp;
            alt = true;
        }
        
        double ycoord = -(ans/x - 250);
        
        x = abs(round(x*100)/100);
        ycoord = abs(round(ycoord*100)/100);
        if(alt){
            printf("%.2f %.2f", ycoord, 0.00);

        }else{
            printf("%.2f %.2f", 0.00, ycoord);
        }

    }

    
    
}
