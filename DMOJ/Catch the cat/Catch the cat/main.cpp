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

ll dis[1000000];

queue <int> Q;

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    Q.push(b);

    while(!Q.empty()){
        int temp = Q.front(); Q.pop();
        if(temp == a){
            continue;
        }else{
            if(temp % 2 == 0 && temp != 0&& temp > a && (dis[temp] + 1 < dis[temp/2] || dis[temp/2] == 0)){
                dis[temp/2] = dis[temp] + 1;
                Q.push(temp/2);
            }
            if(temp > a && (dis[temp-1] > dis[temp]+1 || dis[temp-1] == 0)){
                    dis[temp-1] = dis[temp] +1;
                    Q.push(temp-1);
                }
                if((dis[temp+1] > dis[temp]+1 || dis[temp+1] == 0) && (temp + 1 <= b*2 || b < a)){
                    dis[temp+1] = dis[temp]+1;
                    Q.push(temp + 1);
                }
            }

    }
    cout << dis[a];
}