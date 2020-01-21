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

int maxt[3000];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);

    int N;
    cin >> N;
    string inp = "";
    cin >> inp;
    int sum = 0;
    int prev = -1;
    int cursum = 0;
    prev = -1;
    cursum = 0;
    for(int i = 0; i<inp.length(); i++){
        int maxv = 0;
        int maxend = 0;
        for(int x = i; x<inp.length(); x++){
            string temp = inp.substr(i, x - i+1);
            if(x - i+1 > 0){
            if(prev == -1){
                if(temp[x-i] == 'T'){
                    prev = 1;
                }else{
                    prev = 2;
                }
                maxend =1;
                if(maxend > maxv){
                    maxv= maxend;
                }
            }else if(prev == 1 && temp[x-i] == 'T'){

                maxend += 1;
                if(maxend > maxv){
                    maxv = maxend;
                }
            }else if(prev == 2 && temp[x-i] == 'F'){
                if(maxv == prev){
                    maxend = maxv;
                }
                maxend += 1;
                if(maxend > maxv){
                    maxv = maxend;
                }
            }else{
                maxend = 1;
                if(temp[x-i] == 'T'){
                    prev = 1;
                }else{
                    prev = 2;
                }
                if(maxend > maxv){
                    maxv = maxend;
                }
            }
            
            if(maxv >= (double)(temp.length())/2.0){
                sum ++;
            }
            }
        }
        prev = -1;
    }
    printf("%d\n", sum);
}
