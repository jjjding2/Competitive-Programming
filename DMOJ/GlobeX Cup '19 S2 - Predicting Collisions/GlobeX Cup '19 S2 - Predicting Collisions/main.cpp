#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long double ld;
typedef long long ll;
typedef priority_queue <pair <ll, ll>, vector <pair <ll, ll>>, greater <pair <ll, ll>>> PQ;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

ll gcf (ll a, ll b) {return b == 0? a : gcf (b, a%b);}
ll lcm (ll a, ll b) {return a*b/gcf (a, b);}

int a[6];
int b[6];
int n, m;

ld vala(ld x){
    ld ans = 0;
    for(int i = n; i>= 0; i--){
        ans += a[i]*pow(x, i);
    }
    return ans;
    
}
ld valb(ld x){
    ld ans = 0;
    for(int i = m; i>= 0; i--){
        ans += b[i]*pow(x, i);
    }
    return ans;
    
}
int main(){
    
    //cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    scanf("%d", &n);
    for(int i = n; i>=0; i--){
        cin >> a[i];
    }
    scanf("%d", &m);
    for(int i = m; i>=0; i--){
        cin >> b[i];
    }
    double x1, x2;
    scanf("%lf%lf", &x1, &x2);

    
    
    ld bestv = INF;
    ld besti = -1;
    if(n > 2 || m > 2){
        for(double i = x1; i<= x2; i+= 0.01){
            ld ydif = abs(vala(i) - valb(i));

            bool tan = true;
            if(vala(i - 0.01) - valb(i - 0.01) < 0 && vala(i + 0.01) - valb(i + 0.01) > 0){
                tan = false;
            }else if( vala(i - 0.01) - valb(i - 0.01) > 0 && vala(i + 0.01) - valb(i + 0.01) < 0){
                tan = false;
            }
            if(ydif < bestv && tan == false){
                bestv = ydif;
                besti = i;
            }
        }
    }else{
        for(double i = x1; i<= x2; i+= 0.001){
            ld ydif = abs(vala(i) - valb(i));
            if(ydif < bestv){
                bestv = ydif;
                besti = i;
            }
        }
    }
    for(double i = besti - 0.1; i<= besti + 0.1; i+= 0.0001){
        ld ydif = abs(vala(i) - valb(i));
        if(ydif < bestv){
            bestv = ydif;
            besti = i;
        }
    }
    for(double i = besti - 0.001; i<= besti + 0.001; i+= 0.0000001){
        ld ydif = abs(vala(i) - valb(i));
        if(ydif < bestv){
            bestv = ydif;
            besti = i;
        }
    }
    for(double i = besti - 0.000001; i<= besti + 0.000001; i+= 0.0000000001){
        ld ydif = abs(vala(i) - valb(i));
        if(ydif < bestv){
            bestv = ydif;
            besti = i;
        }
    }
    for(double i = besti - 0.00000001; i<= besti + 0.00000001; i+= 0.000000000001){
        ld ydif = abs(vala(i) - valb(i));
        if(ydif < bestv){
            bestv = ydif;
            besti = i;
        }
    }



    printf("%.10Lf", besti);
    
}
