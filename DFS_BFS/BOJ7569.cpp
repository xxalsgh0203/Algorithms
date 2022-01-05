#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int graph[102][102][102];
queue <pair< int, pair<int, int> > > tomato;

int M, N, H;
int dx[6] = {1,0,-1,0,0,0};
int dy[6] = {0,1,0,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

bool isInRange(int nz, int nx, int ny){
    if(nx>=0 && ny>=0 && nz>=0 && nx<N && ny<M && nz<H)
        return true;
    else 
        return false;
}

void bfs(){

    while(!tomato.empty()){
        int x = tomato.front().second.first;
        int y = tomato.front().second.second;
        int z = tomato.front().first;
        tomato.pop();
        for(int i=0; i<6; i++){
            int nz = z + dz[i];
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(isInRange(nz,nx,ny) && graph[nz][nx][ny]==0){
                graph[nz][nx][ny] = graph[z][x][y] + 1;
                tomato.push(make_pair(nz,make_pair(nx,ny)));
            }
        }
    }
}

int main(){
    int result=0;
    cin >> M >> N >> H;
    for(int k=0; k<H; k++){
        for(int i=0;i<N;i++){
            for(int j=0; j<M; j++){
                cin >> graph[k][i][j];
                if(graph[k][i][j] == 1)
                    tomato.push(make_pair(k,make_pair(i,j)));
            }
        }
    }

    bfs();

    for(int k=0; k<H; k++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(graph[k][i][j] == 0){
                    cout << "-1" << '\n';
                    return 0;
                }
                if(result < graph[k][i][j])
                    result = graph[k][i][j];
            }
        }
    }

    cout << result - 1;

    return 0;

}