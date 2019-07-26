#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int main(){
    int N;
    scanf("%d", &N);
    string ree;
    getline(cin, ree);
    cout << "\n";
    for(int z = 0; z<N; z++){
        string arr[5];

        for(int i = 0; i<4; i++){
            string temp;
            getline(cin, temp);
            int xx;
            for(int x = (int)temp.length()-1; x>=0; x--){
                if(temp[x]!=' '){
                    xx = x;
                    break;
                }
            }
            temp = temp.substr(0, xx+1);
            bool work = false;
            for(int x = (int)temp.length()-1; x >=0; x--){
                if(temp[x]==' '){
                    arr[i] =temp.substr(x+1, temp.length()-1);
                    work = true;
                    break;
                }
            }
            if(!work){
                arr[i] = temp;

            }
            for(int z = 0; z<(int)arr[i].length(); z++){
                (arr[i]).at(z) = tolower(arr[i].at(z));
            }
        }
        

        
        for(int i = 0; i<4; i++){
            bool work;
            for(int x = (int)arr[i].length()-1; x>=0; x--){
                if(arr[i].at(x)=='a' || arr[i].at(x)=='e' ||arr[i].at(x)=='i' ||arr[i].at(x)=='o'||arr[i].at(x)=='u'){
                    
                    arr[i] = arr[i].substr(x, arr[i].length());
                    work = true;
                    break;
                }
            }
      }
        
        if(arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] ){
            cout << "perfect";
        }
        else if(arr[0] == arr[1] && arr[2] == arr[3] && arr[1]!=arr[2]){
            cout << "even";
        }
        else if(arr[0] == arr[2] && arr[1] == arr[3]){
            cout << "cross";
        }
        else if(arr[0] == arr[3] && arr[1] == arr[2]){
            cout << "shell";
        }
        else{
            cout << "free";
        }
        cout << "\n";
         
        
    }
         

}