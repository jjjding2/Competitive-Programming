
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int people[3][3];

int main() {

    for(int i =0  ;i <3; i++){
        for(int x = 0; x<3; x++){
            cin >> people [i][x];
            cout << people[i][x];
        }
        cout << " ";
    }
    int sum = 0;
    
    if(people[0][0]==people[1][1]){
        sum += people[2][1];
    }
    if(people[0][1]==people[1][2]){
        sum += people[2][2];
    }
    if(people[0][2]==people[1][0]){
        sum += people[2][0];
    }
    cout << sum;
}
