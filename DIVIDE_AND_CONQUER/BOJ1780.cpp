#include <iostream>

using namespace std;

int paper[2200][2200];
int one = 0;
int zero = 0;
int minone = 0;

void solve(int x, int y, int size){
    int check = paper[x][y];
    for(int i=x; i<x+size; i++){
        for(int j=y; j<y+size; j++){
            if(check==0 && paper[i][j]!=0){
                check = 2;
            }
            else if(check==1 && paper[i][j]!=1){
                check = 2;
            }
            else if(check==-1 && paper[i][j]!=-1){
                check = 2;
            }

            if(check==2){
                solve(x,y,size/3);
                solve(x+size/3,y,size/3);
                solve(x+size*2/3,y,size/3);
                solve(x,y+size/3,size/3);
                solve(x+size/3,y+size/3,size/3);
                solve(x+size*2/3,y+size/3,size/3);
                solve(x,y+size*2/3,size/3);
                solve(x+size/3,y+size*2/3,size/3);
                solve(x+size*2/3,y+size*2/3,size/3);

                return;
            }
        }
    }
    if(check==0)
        zero++;
    else if(check==1)
        one++;
    else if(check==-1)
        minone++;
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> paper[i][j];
        }
    }
    
    solve(0,0,N);

    cout << minone << '\n';
    cout << zero << '\n';
    cout << one << '\n';

    return 0;
}
