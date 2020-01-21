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

string addition(string a1, string b1){
    //a is larger
    string a, b;
    string c = "";
    if(a1.length() < b1.length()){
        a = b1;
        b = a1;
    }else{
        a = a1;
        b = b1;
    }
    int x = 0;
    for(ll i = (ll)a.length()-1; i >= 0; i--){
        if((i - ((int)a.length() - (int)b.length())) >= 0){
            x+= (int)b[i - (a.length() - b.length())]-48;
        }
        x += (int)a[i]-48;
        c.insert(0, to_string((char)(x%10)));
        if(x >= 10){
            x = (int)x/10;
        }else{
            x = 0;
        }
    }
    if(x > 0){
        c.insert(0, to_string((char)(x%10)));
    }

    return c;
}

string subtraction(string a1, string b1){
    string a, b;
    string c = "";
    int change;
    //if change = true, add a negative to the result, otherwise do not
    if(a1.length() < b1.length()){
        change = 0;
        a = b1;
        b = a1;
    }else if(a1.length() > b1.length()){
        change = 1;
        a = a1;
        b = b1;
    }else{
        change = 2;
    }
    int x = 0;
    if(change == 2){
        for(ll i = 0; i <= (ll)a1.length(); i++){
            if((int)a1[i] > (int)b1[i]){
                change = 1;
                a = a1;
                b = b1;
                break;
            }else if((int)b1[i] > (int)a1[i]){
                change = 0;
                a = b1;
                b = a1;
                break;
            }
        }
        if(change == 2){
            return "0";
        }
    }
    for(ll i = (ll)a.length()-1; i >= 0; i--){
        if((i - ((int)a.length() - (int)b.length())) >= 0){
            x -= (int)b[i - ((int)a.length() - (int)b.length())]-48;
        }
        if((int)a[i]-48 < abs(x)){
            x += ((int)a[i]-48)+10;
            ll count = i-1;
            while(a[count]=='0'){
                a.replace(count, 1, "9");
                count --;
            }
            if(a[count]=='1'){
                a.replace(count, 1, "0");

            }else{
            a.replace(count, 1, to_string(abs((int)a[count]-48-1)));
                          }
        }else{
            x += (int)a[i]-48;
        }
        c.insert(0, to_string((char)(x)));
        x = 0;
        
    }
    if(c[0] == '0'){
        c.erase(0, 1);
    }
    if(change == 0){
        c.insert(0, "-");
    }
    return c;
}
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll N;
    cin >> N;
    for(ll i = 0; i<N; i++){
        string a, b;
        cin >> a >> b;
        if(a[0] == '-' && b[0] == '-'){
            string temp = addition(a.substr(1,a.length()), b.substr(1, b.length()));
            temp.insert(0, "-");
            cout << temp;
        }else if(a[0] == '-'){
            cout << subtraction(b.substr(0,b.length()), a.substr(1, a.length()));
        }else if(b[0] == '-'){
            cout << subtraction(a.substr(0,a.length()), b.substr(1, b.length()));
        }else{
            cout << addition(a.substr(0,a.length()), b.substr(0, b.length()));

        }
        cout << "\n";
    }
}