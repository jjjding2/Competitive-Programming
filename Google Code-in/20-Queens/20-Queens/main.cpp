#include <bits/stdc++.h>

using namespace std;

int n;

int hor[500];
int diaU[1000]; //Upwards diagonal
int diaD[1000]; //Downwards diagonal
int c = 0;

int order[20];

int boardSize;

void print(int hor[100]){
    for(int i = 0; i<n; i++){
        for(int z = 1; z<=n; z++){
            if(hor[z] == i){
                printf("Q ");
            }else{
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
    c ++;
}

void printCoords(int hor[100]){
    for(int i = 1; i<=n; i++){
        printf("%d %d \n", i, hor[i]);
    }
}

void scramble(){
    
    for(int i = 1; i<=100; i++){
        int a = rand()%20 + 1;  //generates random number between 1 and 20
        int b = rand()%20 + 1;
        
        int temp = order[a];
        order[a] = order[b];
        order[b] = temp;
    }
    
}

bool solve(int hor[500], int diaU[1000], int diaD[1000], int spot){
    //This program attempts to fill every column, increasing "spot" until enough queens are placed
    
    if(spot == 20){ //20 can be changed to "n" to solve the n-queens problem
        print(hor); //this functions prints out the entire chess-board
        //printCoords(hor); //this function is used to print the coordinates of each queen
        return true;
    }
    for(int i = 1; i<=n; i++){
        int dia1 = order[i] - spot + n;
        int dia2 = order[i] + spot;
        if(diaU[ dia1 ] == 0 && diaD[dia2] == 0 && hor[ order[i] ] == -1){
            diaU[ dia1 ] = 1;
            diaD[ dia2 ] = 1;
            hor[order[i]] = spot;
            if(solve(hor, diaU, diaD, spot+1)){
                return true; //removing this statement will allow this program to compute every combination
            }
                
            diaU[ dia1 ] = 0; diaD[ dia2 ] = 0; hor[ order[i] ] = -1;
        }
    }
    return false;
}



int main(){
    srand (time(NULL));
    for(int i = 1; i<=20; i++){
        order[i] = i;
    }
    scramble();
    printf("20-Queens Problem\n");
    //scanf("%d", &n);
    
    memset(hor, -1, sizeof(hor));
    
    n = 20;
    printf("The board size is %d\n", n);
    
    solve(hor, diaU, diaD, 0);
    printf("The number of solutions found is %d\n", c);
}
