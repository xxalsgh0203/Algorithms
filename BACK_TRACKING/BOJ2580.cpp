#include <iostream>
using namespace std;
int puzzle[9][9];
bool column[9][9]; // 행
bool row[9][9]; // 열
bool box[9][9];  

void Input(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> puzzle[i][j];
            if(puzzle[i][j] != 0){
                row[i][puzzle[i][j]] = true;
                column[j][puzzle[i][j]] = true;
                box[(i/3) * 3 + (j/3)][puzzle[i][j]] = true;
            }
        }
    }
}

void printPuzzle(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << puzzle[i][j] << " ";
        }
        cout << '\n';
    }
}

void dfs(int cnt){
    int x = cnt / 9;
    int y = cnt % 9;

    if(cnt == 81){
        printPuzzle();
        exit(0);
    }

    if(puzzle[x][y] == 0){
        for(int i=1; i<=9; i++){
            if(!row[x][i] && !column[y][i] && !box[(x/3) * 3 + (y/3)][i]){
                row[x][i] = true;
                column[y][i] = true;
                box[(x/3) * 3 + (y/3)][i] = true;
                puzzle[x][y] = i;
                dfs(cnt + 1);
                row[x][i] = false;
                column[y][i] = false;
                box[(x/3) * 3 + (y/3)][i] = false;
                puzzle[x][y] = 0;
            }
        }
    }
    else
        dfs(cnt + 1);
}

void Solve(){
    dfs(0);
}

int main(){
    Input();
    Solve();
}