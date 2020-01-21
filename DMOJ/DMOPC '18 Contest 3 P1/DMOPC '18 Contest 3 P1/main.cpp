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

string tones [] = {"A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"};

//12

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int a1 = 0;
    int b1 = 0;
    int c1 = 0;
    for(int i = 0; i<12; i++){
        if(a == tones[i]){
            a1 = i;
        }
        if(b == tones[i]){
            b1 = i;
        }
        if(c == tones[i]){
            c1 = i;
        }
    }
    int inversion = 0;

        int a2 = a1;
        int b2 = b1;
        int c2 = c1;
        if(b2 < a1){
            b2 += 12;
        }
        if(c2 < b2){
            c2 += 12;
        }
        string type = "";
        string root = "";
        int first, second;

        if(c2 - b2 > 4){
            inversion = 1;
            second = b2 - a2;
            if(c2 >= 12){
                c2 -= 12;
            }
            if(a2 < c2){
                a2 += 12;
            }
            first = a2 - c2;
            root = c;
        }else if(b2 - a2 > 4){
            inversion = 2;
            first = c2 - b2;
            if(c2 >= 12){
                c2 -= 12;
            }
            if(a2 < c2){
                a2 += 12;
            }
            second = a2 - c2;
            root = b;
        }else{
            first = b2 - a2;
            second = c2 - b2;
            root = a;
        }
    
    if(first == 4 && second == 3){
        type = "major";
    }else if(first == 3 && second == 4){
        type = "minor";
    }else if(first == 4 && second == 4)
    {
        cout << a << "\n";
        cout << "augmented" << "\n";
        cout << "root position" << "\n";
        return 0;
    }else if(first == 3 && second == 3){
        type = "diminished";
    }
    cout << root << "\n";
    cout << type << "\n";
    if(inversion == 0){
        cout << "root position";
    }else if(inversion == 1){
        cout << "first inversion";
    }else if(inversion == 2){
        cout << "second inversion";
    }
}