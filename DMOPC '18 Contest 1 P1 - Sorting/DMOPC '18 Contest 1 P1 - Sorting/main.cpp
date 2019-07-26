#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int arr[2000001];
int wild[100][2];
int main(){
 
    int N;
    scanf("%d", &N);
    int max = 0;
    for(int i = 0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr[i] = temp;
        if(temp < max && temp != 0){
            cout << "NO";
            return 0;
        }else if(temp >max){
            max = temp;
        }
    }
    int count = 0;
    for(int i = 0; i<N; i++){
        if(arr[i] == 0 && i ==0){
            wild[count][0] = 0;
        }
        else if(i != 0 && arr[i] == 0 && arr[i-1]!=0){
            wild[count][0] = arr[i-1];
        }
        
        if(i!=N-1 && arr[i] == 0 && arr[i+1] != 0){
            wild[count][1] = arr[i+1];
            count ++;
        }
        else if(i == N-1 && arr[i] == 0){
            wild[count][1] = wild[count][0];
            count ++;
        }
    }
    for(int z = wild[0][0]; z<=wild[0][1]; z++){
        int work = z;
        bool good = true;
        for(int i = 1; i<count; i++){
            if(work < wild[i][0] || work > wild[i][1]){
                good = false;
            }
        }
        if(good){
            cout << "YES";
            return 0;
        }
    }
        cout << "NO";

    

}