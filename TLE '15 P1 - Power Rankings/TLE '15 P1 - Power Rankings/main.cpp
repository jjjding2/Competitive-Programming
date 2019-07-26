#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

class student{
public:
    string name;
    int total;
    student(){};
    student(string n, int t){
        name = n;
        total = t;
    }
};
bool cmpByName(student A, student B){
    return A.total > B.total;
}

int N, P;
student arr[101];
int main(){
    scanf("%d %d", &N, &P);
    string hi;
    for(int i = 0; i<N; i++){
        string temp;
        cin >> temp;
        arr[i] = student{temp, 0};
    }
    for(int x = 0; x<P; x++) {
        for(int i = 0; i<N; i++){
        int temp;
        scanf("%d", &temp);
        arr[i].total += temp;
        }
    }
    sort(arr, arr + N, cmpByName);
    for(int i = 0; i<N; i++){
        cout <<i + 3<< ". " << arr[i].name << "\n";
    }
    
    
    /*
     #include <bits/stdc++.h>
     using namespace std;
     struct S{ string name; int p;} s[102];
     int N, P;
     bool cmp(S a, S b){return a.p > b.p;}
     int main(){
     cin >> N >> P;
     for(int i=0; i<N; i++){
     cin >> s[i].name; s[i].p=0;
     }
     for(int i=0; i<P; i++){
     for(int j=0, x=0; j<N; j++){
     cin >> x; s[j].p += x;
     }
     }
     sort(s, s+N, cmp);
     for(int i=0; i<N; i++)
     cout << i+3 << ". " << s[i].name << endl;
     }
     */
}