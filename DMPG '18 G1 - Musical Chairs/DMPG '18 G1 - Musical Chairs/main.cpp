#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll,ll> plu;
typedef unordered_map<int,int> umii;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

struct pairs{ int first,second,third; };

vector <pairs> spots;

bool cmpByThird(pairs A, pairs B){
    return A.third < B.third;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 1; i<=K; i++){
        int temp;
        scanf("%d", &temp);
        pairs ree;
         ree.first = 1;
         ree.second = i;
        ree.third = temp;
        spots.push_back(ree);
    }
    
    for(int i = 1; i<=K + 1; i++){
        int temp;
        scanf("%d", &temp);
        pairs ree;
        ree.first = 2;
        ree.second = i;
        ree.third = temp;
        spots.push_back(ree);
    }
    
    sort(spots.begin(), spots.end(), cmpByThird);
    
    while(spots.size() > 1){
        for(int i = 0; i<spots.size(); i++){
            if(i == spots.size()-1){
                if(spots.at(i).first == 2 && spots.at(0).first == 1){
                    spots.erase(spots.begin() + i, spots.begin() +i + 1);
                    spots.erase(spots.begin(), spots.begin() + 1);
                    i--;
                    break;
                }
                if(spots.at(i).first == 1 && spots.at(0).first == 2 && spots.at(i).third == spots.at(0).third){
                    spots.erase(spots.begin() + i, spots.begin() +i + 1);
                    spots.erase(spots.begin(), spots.begin() + 1);                    i--;
                    break;
                }
            }else{
                if(spots.at(i).first == 2 && spots.at(i+1).first == 1){
                    spots.erase(spots.begin() + i, spots.begin() +i+2);
                    i--;
                    break;
                }
                if(spots.at(i).first == 1 && spots.at(i+1).first == 2 && spots.at(i).third == spots.at(i+1).third){
                    spots.erase(spots.begin() + i, spots.begin() +i+2);
                    i--;
                    break;
                }
            }
        }
    }
    cout << spots.at(0).second;
}