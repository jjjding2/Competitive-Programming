#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000


typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

string arr[1000000];
int asdf[1000000][3];

string printer[2];

bool bad[1000000];
int main(){
    int n;
    scanf("%d", &n);
    int maxv = 0;
    int maxi = -1;
    if(n == 0){
        return 0;
    }
    int maxv1;
    for(int i= 0; i<n; i++){
        string d;
        cin >> d;
        arr[i] = d;
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);

        asdf[i][0] = a;
        asdf[i][1] = b;
        asdf[i][2] = c;
        int val = 2*a + 3*b + c;
        if(val > maxv && bad[i] == false){
            maxv = val;
            maxi = i;
        }
    }
    maxv1 = maxv;
        bad[maxi] = true;
    printer[0] = arr[maxi];
    maxv = 0;
    maxi = -1;
    for(int i= 0; i<n; i++){
        int val = 2*asdf[i][0] + 3*asdf[i][1] + asdf[i][2];
        if(val > maxv && bad[i] == false){
            maxv = val;
            maxi = i;
        }
    }
    printer[1] = arr[maxi];
    if(maxv1 == maxv){
        sort(printer, printer + 2);

    }
    if(maxi != -1){
        cout << printer[0] << "\n";
        cout << printer[1];    }
    else{
        cout << printer[0] << "\n";
    }
    

}