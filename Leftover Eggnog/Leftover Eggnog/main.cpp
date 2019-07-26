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

bool cmpBySpeed(pairs A, pairs B){
    return A.first > B.first;
}

queue <pairs> Q;

bool vis[1001][1001];

pairs2 before[1001][1001];

vector <int> adj;

int main(){
    int cup1, cup2, N;
    scanf("%d%d%d", &cup1, &cup2, &N);
    pairs val;
    val.first = 0;
    val.second = 0;
    

    
    Q.push(val);
    pairs temp;
    if(N > max(cup1, cup2)){
        cout << "Not possible";
        return 0;
    }

    while(temp.second != N && temp.first != N){
        bool k = false;
        temp = Q.front(); Q.pop();
        val = temp;
        val.first = cup1;
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 1);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;
        }
        
        val = temp;
        val.second = cup2;
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 2);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;

        }
        
        val = temp;
        val.first = 0;
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 3);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;

        }
        
        val = temp;
        val.second = 0;
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 4);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;

        }
        //a to b
        val = temp;
        val.first = max(0, temp.first - (cup2 -temp.second));
        val.second = min(cup2, temp.first+temp.second);
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 5);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;

        }
        
        //b to a
        val = temp;
        val.second = max(0, temp.second - (cup1 -temp.first));
        val.first = min(cup1, temp.second+temp.first);
        if(!vis[val.first][val.second]){
            before[val.first][val.second] = pairs2(temp.first, temp.second, 6);
            Q.push(val);
            vis[val.first][val.second] = true;
            k = true;
        }
        
        if(!k && Q.empty()){
            cout << "Not possible";
            return 0;
        }
    }
    pairs cur;
    cur.first = temp.first;
    cur.second = temp.second;
    while(cur.first != 0 || cur.second != 0){
        temp.first = before[cur.first][cur.second].first;
        temp.second = before[cur.first][cur.second].second;
        adj.push_back(before[cur.first][cur.second].third);
        cur = temp;
    }
    while(!adj.empty()){
        int newv = adj.back();
        adj.pop_back();
        if(newv == 1){
            cout << "fill A" << "\n";
        }else if(newv == 2){
            cout << "fill B" << "\n";
        }else if(newv == 3){
            cout << "chug A" << "\n";
        }else if(newv == 4){
            cout << "chug B" << "\n";
        }else if(newv == 5){
            cout << "pour A B" << "\n";
        }else if(newv == 6){
            cout << "pour B A" << "\n";
        }

    }
}