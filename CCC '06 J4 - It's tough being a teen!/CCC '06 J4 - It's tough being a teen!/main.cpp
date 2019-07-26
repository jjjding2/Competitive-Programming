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

bool arr[100][100];
queue<int>Q;

bool vis[100];

vector <int> print;

bool printed[100];

bool needprint[100];

queue <int> tempQ;

int main(){
    arr[1][7] = true;
    arr[1][4] = true;
    arr[2][1] = true;
    arr[3][4] = true;
    arr[3][5] = true;
    
    needprint[0] = true;
    needprint[7] = true;
    needprint[4] = true;
    needprint[1] = true;
    needprint[5] = true;
    needprint[3] = true;
    needprint[2] = true;
    
    int count = 6;
    int x1, x2;
    scanf("%d %d", &x1, &x2);
    if(needprint[x2] == false){
        needprint[x2] = true;
        count ++;
    }
    if(needprint[x1] == false)
    {
        needprint[x1] = true;
        count ++;
    }
    while(x1!=0 && x1 != 0){
        arr[x1][x2] = true;
        scanf("%d %d", &x1, &x2);
        if(needprint[x2] == false){
            needprint[x2] = true;
            count ++;
        }
        if(needprint[x1] == false)
        {
            needprint[x1] = true;
            count ++;
        }
    }
    for(int xx = 1; xx<=7; xx++){
        for(int i = 1; i<=7; i++){
            if(needprint[i] == true){
                bool work = true;
                for(int z = 1; z<=7; z++){
                    if(arr[z][i] == true){
                        work = false;
                        break;
                    }
                }
                if(work && printed[i] == false){
                    for(int zz = 1; zz<=7; zz++){
                        if(needprint[zz] == false && printed[zz] == false){
                            if(zz < i){
                                print.push_back(zz);
                                printed[zz] = true;
                            }
                        }
                    }
                    print.push_back(i);
                    printed[i] = true;
                    tempQ.push(i);
                    break;
                }
            }
        }
        while(!tempQ.empty()){
            int f = tempQ.front(); tempQ.pop();
            for(int z = 1; z<=7; z++){
                arr[f][z] = false;
            }
        }
    }
    if(print.size() < count){
        cout << "Cannot complete these tasks. Going to bed.";
    }else{
        cout << print.front();
        print.erase(print.begin());
    while(print.size()!=0){
        cout << " " << print.front();
        print.erase(print.begin());
    }
    }
}