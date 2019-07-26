#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int arr [51];

int main(){
    int N;
    cin >> N;
    for(int i = 0; i<N; i++){
        int x;
        cin >> x;
        arr[i] = x;
    }
    sort(arr, arr + N, greater<int>());

    
    int count =0 ;
    while(arr[1]!=0){
        count ++;
        int z = 1;
        
        arr[0] --;
        while(z!=N-1 && arr[z] > arr[0]){
            z++;
            if(arr[z]>arr[0] && (arr[z+1]<=arr[0] || arr[z+1] == 0)){
                int temp = arr[z];
                arr[z] = arr[0];
                arr[0] = temp;

                
                break;
            }
        }
        int temp = arr[z];
        arr[z] = arr[0];
        arr[0] = temp;
        
        
        arr[1] --;
        z = 0;
        while(z!=N-1){
            z++;
            if(arr[z]>arr[1] && (arr[z+1]<=arr[1] || arr[z+1] == 1)){
                break;
            }
        }
         temp = arr[z];
        arr[z] = arr[1];
        arr[1] = temp;
        
        
        
        
    }
    cout << count << "\n";
    
    
    /*
     #include <bits/stdc++.h>
     
     using namespace std;
     
     #define MOD 1000000007
     
     typedef pair<int, int> pii;
     typedef long long ll;
     typedef pair<ll,ll> plu;
     typedef unordered_map<int,int> umii;
     
     int arr [51];
     int n, m; long long sum = 0;
     int main(){
     scanf("%d", &n);
     for(int i = 0, x; i<n; i++){
     scanf("%d", &x); m = max(m,x); sum += x;
     }
     
     long long rest = sum - m;
     if(m>=rest) printf("%lld\n", rest);
     else printf("%lld\n", sum/2);
     }
     */
}