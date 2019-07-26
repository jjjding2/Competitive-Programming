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


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int v[3];


int fin[300001];

string temp;
string gen(){
    srand(time(NULL));
    string fin = "";
    for(int i = 0; i<12; i++){
        int asdf = rand()%3;
        char tempa = (char)(asdf + 48);
        temp = temp + tempa;
    }
    return fin;
}

int n;
void u1(int val){
    int i = 0;
    while(i < n && v[0]!=n/3){
        if(fin[i]==val){
            v[0] ++;
            v[fin[i]] --;
            fin[i] = 0;
        }
        i++;
    }
    for(int i = 0; i<n; i++){
        cout << fin[i];
    }
    cout << "\n";

}

void u2(int val){
    if(val == 2){
        int i = 0;
        while(i < n && v[1] != n/3){
            if(fin[i]==val){
                v[1] ++;
                v[fin[i]] --;
                fin[i] = 1;
            }
            i ++;
        }
    }else{
        int i = n-1;
        while(i >= 0 && v[1] != n/3){
            if(fin[i]==val){
                v[1] ++;
                v[fin[i]] --;
                fin[i] = 1;
            }
            i --;
        }
        
    }
    for(int i = 0; i<n; i++){
        cout << fin[i];
    }
    cout << "\n";

}

void u3(int val){
    int i = n - 1;
    while(i >= 0 && v[2] != n/3){
        if( fin[i] == val){
            v[2] ++;
            v[fin[i]] --;
            fin[i] = 2;
        }
        i --;
    }
    for(int i = 0; i<n; i++){
        cout << fin[i];
    }
    cout << "\n";
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    cin.tie(0); cin.sync_with_stdio(0);
    gen();
    n = 12;
    /*
    cin >> n;
    cin >> temp;
    */
    temp = "221220111021";
    cout << temp << "\n";
    
    for(int i = 0; i<n; i++){
        v[(int)temp[i] - 48]++;
        fin[i] = (int)temp[i] - 48;
    }
     
    if(v[0] == v[1] && v[1] == v[2]){
        cout << temp;
    }else{
        while(v[0] != v[1] || v[0] != v[2] || v[1] != v[2]){
            int minv = INF;
            int maxv = 0;
            int indice2 = 0;
            int indice = 0;;
            for(int z = 0; z<3; z++){
                if(v[z] < minv || (indice == 1 && z == 2 && v[z] == minv) || (indice == 1 && z == 0 && v[z] == minv)){
                    minv = v[z];
                    indice = z;
                }
            }
            for(int z = 0; z<3; z++){
                if(v[z] > maxv && z != indice){
                    maxv = v[z];
                    indice2 = z;
                }
            }

            if(indice == 0){
                u1(indice2);
            }else if(indice == 1){
                u2(indice2);
            }else if(indice == 2){
                u3(indice2);
            }
        }

        for(int i = 0; i<n; i++){
            cout << fin[i];
        }
    }
    
    
}