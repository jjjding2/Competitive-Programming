#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

bool contains(string row, char a);

int main(){
    int N;
    cin >> N;
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl";
    string row3 = "zxcvbnm";
    bool good = true;
    int sum = 0;
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        if(contains(row1, temp[0])){
            for(int z= 0; z<temp.length(); z++){
                if(!contains(row1, temp[z])){
                    good = false;
                    break;
                }
            }
        }
        if(contains(row2, temp[0])){
            for(int z= 0; z<temp.length(); z++){
                if(!contains(row2, temp[z])){
                    good = false;
                    break;
                }
            }
        }
        if(contains(row3, temp[0])){
            for(int z= 0; z<temp.length(); z++){
                if(!contains(row3, temp[z])){
                    good = false;
                    break;
                }
            }
        }
        
        if(good){
            sum += 1;
        }
        good = true;
    }
    cout << sum;
}

bool contains(string row, char a){
    bool good = false;;
    for(int i = 0; i<row.length(); i++){
        if(row[i] == a){
            good = true;
        }
    }
    return good;
}