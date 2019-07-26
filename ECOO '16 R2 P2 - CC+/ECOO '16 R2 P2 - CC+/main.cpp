#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

/*
	memset(a, 0, sizeof(a));
 */

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second; };

char arr[10000];
int psa[10000];
vector <int> V;
int main(){
    for(int qq = 0; qq<10; qq++){
        ll ASD;
        scanf("%lld", &ASD);
        int N = (int)ASD%26;
        string word;
        getline(cin, word);
        getline(cin, word);
        bool encrypt = false;
        int words = 0;
        int count = 0;
        for(int z = 0; z<=(int)word.size(); z++){
            if(word[z]==' ' || z == (int)word.size()){
                if(z!= (int)word.size()){
                    encrypt = true;
                }
                words ++;
                V.push_back(count);
                count = 0;
            }else{
                count ++;
            }
        }
        if(encrypt){
            arr[0] = (char)((int)words/26 + (int)'a');
            psa[0] = ((int)words/26)%26;
            arr[1] = char(words%26 + (int)'a');
            psa[1] = ((words %26) + psa[0])%26;
            for(int x= 2; x<=words+1; x++){
                arr[x] = (char)(V.front() + 'a');
                psa[x] = (psa[x-1] + (int)arr[x] - 'a')%26;
                V.erase(V.begin());
            }
            int spot = words + 2;
            for(int x = 0; x<word.length(); x++){
                if(word[x] != ' '){
                    arr[spot] = word[x];
                    psa[spot] = (psa[spot-1] +(int)word[x]-'a')%26;
                    spot ++;
                }
            }
            for(int x = 0; x<spot; x++){
                arr[x] = (char)(((int)arr[x] - 'a'+ (psa[spot-1] - psa[x]+52)%26 + N + 52)%26 + 'a');
            }
            for(int x = 0; x<spot; x++){
                cout << arr[x];
            }
            cout << "\n";

        }else{
            for(int i = (int)word.length()-1; i>=0; i--){
                arr[i] = (word[i] - 'a' -N - psa[i+1] + 78) %26 + 'a';
                psa[i] = (psa[i+1] + arr[i]-'a' + 26)%26;
            }
            words = (arr[0]-'a')*26 + arr[1] - 'a';
            int counter = 0;
            for(int i = 0; i<words; i++){
                int temp = arr[2 + i] - 'a';
                for(int f = 0; f<temp; f++){
                    cout << arr[words + 2 + counter];
                    counter ++;
                }
                if(i!=words-1){
                    cout << " ";
                }
            }
            cout << "\n";
            
        }
        memset(psa, 0, sizeof(psa));
        memset(arr, 0, sizeof(arr));
        V.clear();


    }
}