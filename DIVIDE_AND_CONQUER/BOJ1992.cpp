#include <iostream>
#include <stdio.h>
using namespace std;

int quadtree[64][64];

void solve(int x, int y, int size){
    int check = quadtree[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(check == 0 && quadtree[i][j] == 1){
                check = 2;
                cout << "(";
            }
            else if(check == 1 && quadtree[i][j] == 0){
                check = 2;
                cout << "(";          
            }
            if(check == 2){
                solve(x,y,size/2);
                solve(x,y+size/2,size/2);
                solve(x+size/2,y,size/2);
                solve(x+size/2,y+size/2,size/2);
                cout << ")";
                return;
            }
        }
    }
    if(check==0)
        cout << 0;
    else
        cout << 1; 
}
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &quadtree[i][j]);
        }
    }

    solve(0,0,N);

    return 0;
}
