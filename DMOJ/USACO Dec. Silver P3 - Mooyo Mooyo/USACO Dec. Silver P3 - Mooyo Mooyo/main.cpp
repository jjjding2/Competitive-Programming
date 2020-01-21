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

char arr[101][11];

int N, K;

void print(){
    
}
bool gravity(){
    bool work = false;
    for(int i = 1; i<= 10; i++){
        int zero = N;
        for(int z = N; z >= 1; z--){
            if(arr[z][i] == '0'){
                zero = z;
                for(int f = z-1; f>= 1; f --){
                    if(arr[f][i] != '0'){
                        arr[zero][i] = arr[f][i];
                        arr[f][i] = '0';
                        work = true;
                        break;
                    }
                }
            }

        }
        
    }
    return work;
}

queue <pii> q;

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[101][11];

void remove(){
    for(int i = 1; i<=N; i++){
        for(int z = 1; z<11; z++){
            if(vis[i][z] == 2){
                vis[i][z] = 1;
                arr[i][z] = '0';
            }
        }
    }
}

void remove2(){
    for(int i = 1; i<=N; i++){
        for(int z = 1; z<11; z++){
            if(vis[i][z] == 2){
                vis[i][z] = 1;
            }
        }
    }
}

bool clear(){
    for(int i = 1; i<=N; i++){
        for(int z = 1; z<11; z++){
            vis[i][z] = 1;
        }
    }
    bool work = false;
    for(int i = 1; i<= 10; i++){
        for(int z = N; z >= 1; z--){
            
            //0 is visited
            //1 is unvisited
            //2 is temp
            
            if(vis[z][i] == 1 && arr[z][i] != '0'){
                
                int cursum = 1;
                vis[z][i] = 2;
                q.push({z, i});
                char cur = arr[z][i];
                while(!q.empty()){
                    pii temp = q.front(); q.pop();
                    int curx = temp.first; int cury = temp.second;
                    for(int i = 0; i<4; i++){
                        int newx = curx + d[i][0]; int newy = cury + d[i][1];
                        
                        if(vis[newx][newy] ==1 && arr[newx][newy] == cur){
                            q.push({newx, newy});
                            vis[newx][newy] = 2;
                            cursum ++;
                        }
                    }
                }
                if(cursum >= K){
                    remove();
                    work = true;
                }else{
                    remove2();
                }
                
            }
            
        }
        
    }
    return work;
}


int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    ifstream cin ("mooyomooyo.in");
    ofstream cout ("mooyomooyo.out");
    
    cin >> N >> K;
    for(int i = 1; i<=N; i++){
        string temp;
        cin >> temp;
        for(int z = 1; z<=10; z++){
            arr[i][z] = temp[z-1];
        }
    }
    while(clear() == true && gravity() == true){
        clear();
        gravity();
    }
    for(int i = 1; i<=N; i++){
        for(int z = 1; z<= 10; z++){
            cout << arr[i][z];
        }
        if(i!=N){
            cout << "\n";
        }
        
    }
}