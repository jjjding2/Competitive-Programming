#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#include <time.h>

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int arr[100005];

string gen(){
    srand(time(NULL));
    int temp = rand()%100 + 100;
    string fin = "";
    for(int i = 0; i<temp; i++){
        int asdf = rand()%2;
        if(asdf == 0){
            fin.append("R");
        }else{
            fin.append("L");
        }
    }
    cout << fin << endl;
    return fin;
}
//RLRLLRLRRLRRR
//LRLRLLRRLRRRR
//LLRLRLRLRRRRR
//LLLRLRLRRRRRR
//LLLLRLRRRRRRR
//LLLLLRRRRRRRR

void BF(string temp){
    for(int i = 0; i<temp.length(); i++){
        bool work = false;
        for(int z = 0; z<temp.length()-1; z++){
            if(temp[z] == 'R' && temp[z+1] == 'L'){
                work = true;
                temp[z+1] = 'R';
                temp[z] = 'L';
                z ++;
            }
        }
        if(!work){
            cout << i << endl;
            break;
        }
    }
}

int main(){
    int N2;
    cin >> N2;
    string temp;
    
    cin >> temp;
    N2 = (int)temp.length();
    int N = N2;

    bool found = false;
    int first = -1;
    int Rcount = 0;
    int jam = 0;
    int totsum = 0;
    for(int i = 0; i<N; i++){
        if(temp[i] == 'R'){
            if(!found){
                first = i;
                found = true;
                Rcount += 1;
                bool first = false;
                    while(i<N-1){
                        if(temp[i+1] == 'R'){
                            first = true;
                            jam --;
                            Rcount += 1;

                        }else{
                            if(first == true){
                                if(jam < 0){
                                    first = false;
                                    totsum += jam;
                                    jam = 0;
                                }

                            }
                            jam ++;
                        }
                        i ++;
                    }
                
            }
        }
    }
    if(totsum > 0){
        totsum = 0;
    }
    if(found){
        cout << N2 - Rcount - first - totsum << "\n";
    }else{
        cout << 0;
    }
}