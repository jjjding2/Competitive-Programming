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

string arr[1005];
int n;

string reverse(string str)
{
    int n = (int)str.length();

    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
    return str;
}

int solve(int start, int end, int pos){
    int curans = end - start + 1;
    
    int size = end - start + 1;
    
    if(end - start + 1 == 2 && pos != 0){
        return 2;
        
    }else if(end - start + 1 < 2){
        
        return 0;
        
    }else if(pos > arr[start].length()){
        
        if(size >= 2){
            return 2;
            
        }else{
            return 0;
        }
        
    }else{
    
        for(int i = start; i<=end; i++){
            int cur = i;
            while(i + 1 <= end && (pos >= arr[i+1].length() || arr[i+1][pos] == arr[i][pos] )){
                i ++;
            }
            curans -= solve(cur, i, pos + 1);
            
        }
        if(pos == 0){
            return size - curans;
            
        }
        else if(curans >= 2){
            return size - (curans - 2);
        }else{
            return size - curans;
        }
    }
    
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("file.in","r",stdin); freopen("file.out","w",stdout);
    
    int T;
    cin >> T;
    for(int i = 0; i<T; i++){
        cin >> n;
        for(int i = 0; i<n; i++){
            string temp;
            cin >> temp;
            arr[i] = reverse(temp);
        }
        sort(arr, arr + n);
        
        /*
        for(int i = 0; i<n; i++){
            cout << arr[i] << "\n";
            
        }
        */

        cout << "Case #" << i + 1 << ": " << solve(0, n - 1, 0) << "\n";
        
    }
    
}
