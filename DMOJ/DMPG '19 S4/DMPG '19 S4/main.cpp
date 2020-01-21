#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define INF 0x3f3f3f3f
typedef pair<int, int> pii;

map<string, vector<string>> graph;

map<string, bool> check;

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n, m, q;
    cin >> n >> m >> q;
    for (int a = 0; a < n; a++) {
        string holder;
        cin >> holder;
    }
    for (int a = 0; a < n; a++) {
        string l, x;
        cin >> l >> x;
        graph[l].push_back(x);
        graph[x].push_back(l);
    }
    for (int a = 0; a < q; a++) {
        string l;
        char x;
        cin >> l >> x;
        queue<string> hold;
        hold.push(l);
        check[l] = true;
        bool found = false;
        while (!found && !hold.empty()) {
            string shold = hold.front();
            if (shold[0] == x) {
                cout << shold << "\n";
                found = true;
            }
            else {
                for (int ix = 0; ix < graph[shold].size(); ix++) {
                    if (!check[graph[shold][ix]]) {
                        hold.push(graph[shold][ix]);
                        check[graph[shold][ix]] = true;
                    }
                }
            }
            hold.pop();
        }
        if (!found) {
            cout << -1 << "\n";
        }
    }
}
