#include <iostream>

using namespace std;
int graph[100][100];
int visited[100][100];
int N, M;
int cnt = 1;

bool dfs(int x, int y){
    if(x<0 || y<0 || x>=N || y>=N){
        return false;
    }
    if(graph[x][y] == 1 && visited[x][y] == 0){
        cnt++;
        visited[x][y] = 1;
        graph[x][y] = cnt;
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y+1);
        dfs(x, y-1);
        return true;
    }
    return false;
}

int main(){

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graph[i][j];
        }
    }

    dfs(0,0);

    cout << graph[N][M] << endl;

    return 0;
}