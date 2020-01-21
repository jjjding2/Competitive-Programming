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

bool vis[1001][1001];

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

queue <pii> q;

queue <int> edge;

int maxx, maxy;

int arr[3][2];

pii pre[1001][1001];

bool works(int e){
    
    for(int i = 0; i<3; i++){
        
        q.push({arr[i][0], arr[i][1]});
        edge.push(e);
        vis[arr[i][0]][arr[i][1]] = true;
        
        while(!q.empty()){
            
            int curx = q.front().first;
            int cury = q.front().second; q.pop();
            int cure = edge.front(); edge.pop();
            if(cure > 0){
                for(int z = 0; z<4; z++){
                    int newx = curx + d[z][0];
                    int newy = cury + d[z][1];
                    if(newx >= 0 && newy >= 0 && newx <= maxx && newy <= maxy && !vis[newx][newy]){
                        q.push({newx, newy});
                        edge.push(cure - 1);
                        pre[newx][newy] = {curx, cury};
                        vis[newx][newy] = true;
                    }
                }
            }
            
        }
        bool work = true;
        for(int z = 0; z<3; z++){
            if(!vis[arr[z][0]][arr[z][1]]){
                work = false;
            }
        }
        memset(vis, false, sizeof(vis));

        if(work){
            return true;
        }
    }
    return false;
    
}

int main(){
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    for(int i = 0; i<3; i++){
        scanf("%d%d", &arr[i][0], &arr[i][1]);
        maxx = max(maxx, arr[i][0]);
        maxy = max(maxy, arr[i][1]);
    }
    int low = 0;
    int high = maxx*maxy;
    int mid = (low + high)/2;
    int ans = 0;
    while(low <= high){
        if(works(mid)){
            high = mid - 1;
            ans = mid;
        }else{
            low = mid + 1;
        }
        mid = (low + high)/2;
    
    }
    cout <<ans;
    
}