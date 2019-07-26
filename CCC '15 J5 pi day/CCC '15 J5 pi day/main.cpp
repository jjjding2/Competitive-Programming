//
//  main.cpp
//  CCC '15 J5 pi day
//
//  Created by Jason UTS on 2018-08-06.
//  Copyright © 2018 Jason UTS. All rights reserved.
//
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int people[100];
int pie, k;
int ktot;
int total = 0;
int maxv = 0;
//n = pie, k = people


void choose(int n, int k, int people[], int index){
    if(index == ktot && n == 0){
        total ++;
        for(int i = 0; i<ktot; i++){
            cout << people[i];
        }
        cout <<" ";
    }
    
    else{
        int startv;
        if(index != 0){
            startv = people[index-1];
            
        }else{
            startv = 1;
        }
        int less;
        if(index == 0){
            less = n/k;
        }else{
            less =(pie-(pie-n)-(k-index-1));

        }
        for(int i = startv; i<=less; i++){
            
            if((i*(ktot-index))<=n && n-i>=0 && index + 1 <= ktot){
                
                people[index] = i;
                choose(n-i, k, people, index+1);
            }
        }
    
    }
}

int main() {
    cin >> pie;
    cin >> k;
    ktot = k;
    for(int i = 0; i<k; i++){
        people[i] = 1;
    }
    maxv = pie/k;
    if(pie==k){
        cout << "1";
    }
    else if (k ==1){
        cout <<"1";
    }
    else{
        choose(pie, k, people, 0);
        cout << total;
    }
}
