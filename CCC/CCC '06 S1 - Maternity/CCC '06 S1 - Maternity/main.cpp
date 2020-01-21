#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }


int p1 [100];
int p2[100];



int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    string a;
    cin >> a;
    string b;
    cin >> b;
    
    //t lower, f capital
    
    for(int i = 0; i < 10; i+=2){
        if(a[i] >='a' && a[i + 1] >= 'a'){
            p1[i/2] = 1;
        }else if((a[i] >= 'a' && a[i+1] >= 'A') || (a[i] >= 'A' && a[i+1]>= 'a')){
            p1[i/2] = 2;
        }else if(a[i] >= 'A' && a[i + 1] >= 'A'){
            p1[i/2] = 0;
        }
        
        if(b[i] >='a' && b[i + 1] >= 'a'){
            p2[i/2] = 1;
        }else if((b[i] >= 'a' && b[i+1] >= 'A') || (b[i] >= 'A' && b[i+1]>= 'a')){
            p2[i/2] = 2;
        }else if(b[i] >= 'A' && b[i + 1] >= 'A'){
            p2[i/2] = 0;
        }
    }
    int N;
    cin >> N;
    for(int f = 0; f<N; f++){
        string temp;
        cin >> temp;
        bool work = true;
        for(int i = 0; i<5; i++){
            bool capital = false;
            if(temp[i] >= 'a'){
                capital = false;
            }else{
                capital = true;
            }
            if(p1[i] == 2 && p2[i] == 2){
                continue;
            }else{
                if(p1[i] == 2){
                    p1[i] = 0;
                }
                if(p2[i] == 2){
                    p2[i] = 0;
                }
            }
                
            if(!capital && (p1[i] == 1 || p2[i] == 1) && !(b[i*2] >= 'a' && b[i*2 + 1] >= 'a' && a[i*2] < 'a' && a[i*2 + 1] < 'a')){
                continue;
            }else if(capital && (p1[i] == 0 || p2[i] == 0)){
                continue;
            }else{
                cout << "Not their baby!" << "\n";
                work = false;
                break;
            }
        }
        if(work == true){
            cout << "Possible baby." << "\n";
        }
    
    }
    
    
}