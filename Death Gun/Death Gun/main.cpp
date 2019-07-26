#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define MAXN 1000

typedef pair<int, int> pii;
//{v, w}
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<string,int> hmap;

hmap mymap;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <int> adj[10000];

int in[10000];

string name[10000];

int main(){
    int N;
    scanf("%d", &N);
    int count = 0;
    for(int i = 0; i<N; i++){
        string a;
        string b;
        cin >> a >> b;
        if(mymap.count(a) == 0){
            mymap.emplace(a, count);
            name[count] = a;
            count ++;
        }
        if(mymap.count(b) == 0){
            mymap.emplace(b, count);
            name[count] = b;
            count ++;
        }
        adj[mymap[b]].push_back(mymap[a]);
        in[mymap[a]]++;
    }
    bool work = true;
    while(work){
        work = false;
        for(int i = 0; i<count; i++){
            if(in[i] == 0){
                work = true;
                in[i] = -1;
                cout << name[i] << "\n";
                for(int j: adj[i]){
                    in[j]--;
                }
                break;
            }
        }
    }
}