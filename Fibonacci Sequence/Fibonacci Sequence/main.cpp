#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef unsigned long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };


unsigned long long M[2][2] = {{1,0},{0,1}};

unsigned long long orig[2][2] = {{1,1},{1,0}};

int mod = 1000000007;
void matrix(){
    unsigned long long x1 = M[0][0]%mod*M[0][0]%mod + M[0][1]%mod*M[0][1]%mod;
    unsigned long long x2 = M[0][1]%mod*M[0][0]%mod + M[1][1]%mod*M[1][0]%mod;
    unsigned long long y1 =M[0][1]%mod*M[0][0]%mod +M[1][1]%mod*M[1][0]%mod;
    unsigned long long y2 = M[1][1]%mod*M[1][1]%mod + M[0][1]%mod*M[0][1]%mod;
    M[0][0] = x1%mod;
    M[0][1] = x2%mod;
    M[1][0] = y1%mod;
    M[1][1] = y2%mod;
}

void matrixOdd(){
    unsigned long long x1 = M[0][0]%mod*orig[0][0]%mod + M[0][1]%mod*orig[0][1]%mod;
    unsigned long long x2 = M[0][1]%mod*orig[0][0]%mod + M[1][1]%mod*orig[1][0]%mod;
    unsigned long long y1 =M[0][1]%mod*orig[0][0]%mod +M[1][1]%mod*orig[1][0]%mod;
    unsigned long long y2 = M[1][1]%mod*orig[1][1]%mod + M[0][1]%mod*orig[0][1]%mod;
    M[0][0] = x1%1000000007;
    M[0][1] = x2%1000000007;
    M[1][0] = y1%1000000007;
    M[1][1] = y2%1000000007;
}

void linpow(ll N){
    if(N>1){
        linpow(N/2);
        matrix();
    }
    if(N%2==1){
        matrixOdd();
        N--;
    }
}

unsigned long long fib(ll N){
    
    linpow(N);
    return M[0][0];
}

            /*
void pow(ll x, ll orig){
    if(x%2==1 && x!=1){
        n = n*orig;
        x--;
    }
    if(x>1){
        n = n * n;
        pow(x/2, orig);
    }
}
             */

int main(){
    unsigned long long N;
    cin >> N;
    unsigned long long x = fib(N-1);
    cout << x %1000000007;
}