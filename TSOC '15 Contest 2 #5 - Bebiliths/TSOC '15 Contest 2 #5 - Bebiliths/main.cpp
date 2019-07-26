#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

class beb{
public:
    ll speed;
    ll venom;
    ll claw;
    ll place;
    beb(){}
    beb(ll s, ll v, ll c, ll p){
        speed = s;
        venom = v;
        claw = c;
        place = p;
    }
    
};

bool cmpBySpeed(beb A, beb B){
    return A.speed > B.speed;
}


bool cmpByClaw(beb A, beb B){
    return A.claw > B.claw;
}

bool cmpByVenom(beb A, beb B){
    return A.venom > B.venom;
}

beb arr[500001];
ll pos[500001];

int main(){
    int S, N;
    scanf("%d %d", &S, &N);
    for(ll i = 0, x, y, z; i<N; i++){
        cin >> x >> y >> z;
        arr[i] = beb(x, y, z, i);
    }
    sort(arr, arr + N, cmpBySpeed);
    
    for(int i = 0; i<N; i++){
        if(arr[i].speed == arr[i+1].speed){
            ll speed = arr[i].speed;
            int N1 = i;
            while(arr[i+1].speed == arr[i].speed){
                i++;
            }
            int N2 = i;
            if(speed >= S){
                sort(arr + N1, arr + N2 + 1, cmpByClaw);
            }
            else if (speed< S){
                sort(arr + N1, arr + N2 + 1, cmpByVenom);
            }
            
        }
    }
    
    
    for(int i = 0; i<N; i++){
        pos[i+1] = arr[i].place+1;
    }
    ll z;
    cin >> z;
    for(int i = 0; i<z; i++){
        ll temp;
        cin >> temp;
        cout << pos[temp] << "\n";
    }
}