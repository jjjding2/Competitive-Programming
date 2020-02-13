#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


struct edge {int a; int b; int v;};

bool cmp(edge a, edge b){
    return a.v < b.v;
}
edge e[100003];

int p[50005][400];

int Find(int d, int e){
    
    if(d != p[d][e]){
        p[d][e] = Find(p[d][e], e);
    }
    return p[d][e];
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    
    int n, m, q;
    cin >> n >> m >> q;
    
    for(int i = 0; i<n; i++){
        for(int z = 0; z<=300; z++){
            p[i][z] = i;
        }
    }
    for(int i = 0; i<m; i++){
        int a, b, v;
        cin >> a >> b >> v;
        e[i] = {a,b,v};
    }
    
    for(int i = 0; i<m; i++){
        int cur = e[i].v;
        for(int z = cur; z<=300; z++){
            int bruh = z & cur;
            if(bruh == cur){
                int u = Find(e[i].a,z); int v = Find(e[i].b, z);
                if(u!=v){
                    p[u][z] = v;
                }
            }
        }
    }
    for(int i = 0; i<q; i++){
        int a, b;
        cin >> a >> b;
        bool work = false;
        for(int z = 0; z<=300; z++){
            if(Find(a, z) == Find(b, z)){
                cout << z << "\n";
                work = true;
                break;
            }
        }

    }
}
