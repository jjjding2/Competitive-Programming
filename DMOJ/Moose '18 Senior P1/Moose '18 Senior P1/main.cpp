#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f



typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

//cin.tie(0); cin.sync_with_stdio(0);

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

vector <int> adj[2];

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    cin.tie(0); cin.sync_with_stdio(0);

    int D;
    cin >> D;
    for(int i = 0; i<D; i++){
        
        
        int length1;
        cin >> length1;
        string song;
        int sum = 0;
        adj[0].push_back(0);
        for(int x = 0; x<length1; x++){
            string word2;
            cin >> word2;
            sum += word2.length() + 1;
            adj[0].push_back(sum );
            song = song + word2 + " ";
        }
        int length;
        cin >> length;
        int start =0 ;
        int end = 0;
        
        string nword = "";
        adj[1].push_back(0);
        sum = 1;
        for(int x = 0; x<length; x++){
            string word2;
            cin >> word2;

            int z = 0;
                if(word2[z] == 'n'){
                    int x = 0;
                    start = z;
                    bool work = true;
                    while(true){
                         if(x%2 == 1 && word2[z] != 'a'){
                             work = false;
                            break;
                        }else if(x%2 == 0 && word2[z] != 'n'){
                            work = false;
                            break;
                        }else if(z == word2.length() - 1){
                            break;
                        }
                        x ++;
                        z ++;
                    }
                    if(work){
                        nword = nword + "1 ";
                        if(x!= length-1){
                        sum = nword.length();
                        }
                        adj[1].push_back(sum);
                    }
                    
                }else{
                    nword = nword + word2 + " ";
                    if(x!= length-1){

                    sum = nword.length();
                    }
                    adj[1].push_back(sum);
                }
            
        }
    
        bool asdf = false;
        
        for(int j: adj[0]){
            if(adj[0].size() - j <= (int)adj[1].size()){
                break;
            }
            int index = 1;
            int z = j;
            for( z = j + 1; z < min(adj[0].size(), adj[1].size()); z++){
                string temp1 =nword.substr(adj[1][index-1], adj[1][index]-adj[1][index-1]);
                string temp2 =song.substr(adj[0][z - 1], adj[0][z]-adj[0][z - 1]);
                if(temp1 == "1 "){
                    index ++;
                    continue;
                }
                else if(nword.substr(adj[1][index-1], adj[1][index]) == song.substr(adj[0][z - 1], adj[0][z])){
                    index ++;
                }else{
                    break;
                }
            }
            if(z == min(adj[0].size(), adj[1].size())){
                cout << "Yes" << "\n";
                asdf = true;
                break;
            }
        }
        if(!asdf){
            cout << "No";
        }
        
        adj[0].clear();
        adj[1].clear();
    }
    
    
}