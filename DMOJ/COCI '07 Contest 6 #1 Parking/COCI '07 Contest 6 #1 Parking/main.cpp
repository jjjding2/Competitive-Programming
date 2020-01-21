#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

class pairs{
public:
    int first;
    int second;
    pairs(){}
    pairs(int firsta, int seconda){
        first = firsta;
        second = seconda;
    }
    
};

class pairs2{
public:
    int first;
    int second;
    int third;
    pairs2(){}
    pairs2(int firsta, int seconda, int thirda){
        first = firsta;
        second = seconda;
        third = thirda;
    }
    
};

int arr[101];
int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    for(int i = 0; i<3; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        arr[x] += 1;
        arr[y] -= 1;
    }
    int cur = 0;
    int sum = 0;
    for(int i = 1; i<=100; i++){
        cur += arr[i];
        if(cur == 1){
            sum += a;
        }else if(cur == 2){
            sum += b*2;
        }else if(cur == 3){
            sum += c*3;
        }
    }
    printf("%d", sum);
}