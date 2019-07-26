
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


long long people[3];




int main() {
    long long one;
    long long two;
    
    cin >> one;
    cin >> two;
    
    people[0] = one + two;
    long long dif = one - two;
    people[1] = abs(dif);
    
    people[2] = one * two;
    sort(people, people + 3);
    cout << people[2];
    
}
