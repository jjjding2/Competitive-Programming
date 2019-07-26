#include <bits/stdc++.h>

using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pb push_back
#define MOD 1000000007
#define MAXN 1000
#define INF 0x3f3f3f3f
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
ll fpow(ll b, ll exp, ll mod){if(exp == 0) return 1;ll t = fpow(b,exp/2,mod);if(exp&1) return t*t%mod*b%mod;return t*t%mod;}

priority_queue<int, vector<int>, greater<int>>q;

string arr[5000];
char first[5000];
char last[5000];

int code['Z'][1000];

int freq[1000][1000];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("DATA22.txt","r",stdin);
    for(int y = 0; y<10; y++){
        int rule, n;
        cin >> rule >> n;
        string start;
        cin >> start;
        
        unsigned long long ans = 0;
        
        for(int z = 0; z<start.length(); z++){
            freq[0][(int)start[z]] ++;
        }
        
        for(int i = 0; i<rule; i++){
            string a;
            cin >> a;
            
            string b;
            cin >> b;
            
            for(int z = 0; z<b.length(); z++){
                code[(int)a[0]][(int)b[z]] ++;
            }
            
            arr[(int)a[0]] = b;
            
            first[(int)a[0]] = b[0];
            last[(int)a[0]] = b[b.length()-1];
        }
        
        char firstc = start[0];
        char lastc = start[start.length()-1];
        
        for(int i = 1; i<=n; i++){
            firstc = first[(int)firstc];
            lastc = last[(int)lastc];
            
            for(int x = (int)'A'; x<=(int)'Z'; x++){
                for(int z = (int)'A'; z<=(int)'Z'; z++){
                    freq[i][z] += freq[i - 1][x] * code[x][z];
                }
                
            }

            
        }
        for(int i = (int)'A'; i <= (int)'Z'; i++){
            ans += freq[n][i];
        }
        cout << firstc << lastc << " " << ans << "\n";
        memset(freq, 0, sizeof(arr));
        memset(code, 0, sizeof(code));
    }

    
}
