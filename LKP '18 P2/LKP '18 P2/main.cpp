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

ll arr[100000];

ll printer[10];

bool vis[1000000];

int main(){
    int N;
    scanf("%d", &N);
    for(int f = 0; f<N; f++){

        ll D = 0;
        scanf("%lld", &D);
        for(int z = 0; z<(D+1); z++){
            scanf("%lld", &arr[z]);
        }
        for(int z = 0; z<10; z++){
            printer[z] = max(arr[0], arr[D]);
        }
        ll n = abs(arr[0]);
        ll d = abs(arr[D]);
        ll count = 0;
        bool d1 = false;
        bool n1 = false;
        bool work = false;
        for(ll y = 1; y<=sqrt(d); y++){
            if(d%y == 0 && y!= 0){
                for(ll i=1; i<=sqrt(n); i++){
                    if(n%i == 0 && i!= 0){
                        for(int xx = 0; xx<2; xx ++){
                            y = y * -1;
                            if(y <= 0 && i <= 0){
                                continue;
                            }
                            if(count == D){
                                break;
                            }
                            double sum = 0;
                            for(int z = 0; z<(D+1); z++){
                                sum += pow((ll)y/i, D - z) * arr[z];
                            }
                            work = false;
                            if(sum == 0 && (ll)y/i != 0){
                                bool work1 = true;
                                for(int ff = 0; ff<count+1; ff++){
                                    if(printer[ff] == (ll)y/i){
                                        work1 = false;
                                        break;
                                    }
                                }
                                if(work1){
                                printer[count] = (double)y/i;
                                count ++;
                                work = true;
                                }
                            }
                        }
                        
                        if(count == D){
                            break;
                        }
                        if(n1){
                            n = sqrt(n);
                            i = d/i;
                            n1 = false;
                        }else{
                            if(i!=1 && i != sqrt(n)){
                                i = d/i-1;
                                n1 = true;
                                n = sqrt(n);
                            }
                        }
                    }
                    if(count == D){
                        break;
                    }
                    if(count != D){
                        sort(printer, printer + D);

                        ll temp = arr[D];
                        for(int i = 0; i<count; i++){
                            temp = temp/printer[i];
                        }
                        for(int i = 0; i<count; i++){
                            if(abs(temp) % (ll)abs(printer[i]) == 0){
                                int sum = 0;
                                for(int z = 0; z<(D+1); z++){
                                    sum += pow((ll)printer[i], D - z) * arr[z];
                                }
                                if(sum == 0){
                                    printer[count] = printer[i];
                                    count ++;
                                    break;
                                }
                            }
                        }
                    }
                    
                }
                if(d1){
                    d = sqrt(d);
                    y = d/y;
                    
                    d1 = false;
                }else{
                    if(y!=1 && y != sqrt(d)){
                        y = d/y-1;
                        d = d*d;
                        d1 = true;
                    }
                }            }
            if(count == D){
                break;
            }
        }
        sort(printer, printer + D);
        if(count != D){
            sort(printer, printer + D);
            
            ll temp = arr[D];
            for(int i = 0; i<count; i++){
                temp = temp/printer[i];
            }
            for(int i = 0; i<count; i++){
                if(abs(temp) % (ll)abs(printer[i]) == 0){
                    int sum = 0;
                    for(int z = 0; z<(D+1); z++){
                        sum += pow((ll)printer[i], D - z) * arr[z];
                    }
                    if(sum == 0){
                        printer[count] = printer[i];
                        count ++;
                        break;
                    }
                }
            }
        }
        sort(printer, printer + D);
        for(int i = 0; i<D; i++){
            printf("%lld", (ll)printer[i]);
            if(i!=D-1){
                printf(" ");
            }
        }
        for(int z = 0; z<10; z++){
            printer[z] = 100000;
        }        printf("\n");
        
    }
}