#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;
int arr[101];
int work[1000000];
bool done[1000000];
vector <int>adj;
int main(){
    int N;
    scanf("%d", &N);
    for(int i= 0 ; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
    }
    sort(arr, arr + N);
    for(int i = arr[N/16]; i>2; i--){
        adj.push_back(i);
    }
    int addcount = 0;
    while(!adj.empty()){
        int i = adj.back();
        adj.pop_back();
        int track = arr[0]%i;
        bool yay = true;
        for(int z = 0; z<N; z++){
            if(arr[z]%i != track){
                yay = false;
                break;
            }
        }
        if(yay){
            if(done[i] == false){
                done[i] = true;
            work[addcount] = i;
            addcount ++;
            }
            for(int z = 2; z<i/2; z++){
                if(done[z] == false && i%z == 0){
                    done[z] = true;
                    adj.erase(remove(adj.begin(), adj.end(), z), adj.end());
                    work[addcount] = z;
                    addcount ++;
                }
            }
        }
    }
    sort(work, work + addcount);
    for(int i = 0; i<addcount; i++){
        cout <<work[i] << " ";
    }
}