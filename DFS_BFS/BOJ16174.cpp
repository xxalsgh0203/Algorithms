#include <iostream>
using namespace std;

int N;
int map[64][64];
bool visited[64][64];
bool result;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];
        }
    }
}

bool inRange(int x, int y){
    return x>=0 && x<N && y>=0 && y<N;
}

void dfs(int x, int y){
    if(x==N-1 && y==N-1){
        visited[N-1][N-1] = true;
        return;
    }
    if(inRange(x,y) && !visited[x][y]){
        visited[x][y] = true;
        dfs(x+map[x][y],y);
        dfs(x,y+map[x][y]);
    }
}

int main(){
    Input();
    dfs(0,0);
    if(visited[N-1][N-1] == true)
        cout << "HaruHaru";
    else
        cout << "Hing";
}