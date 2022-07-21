#include <iostream>
#include <queue>
using namespace std;
char map[102][102];
bool visited[102][102];
int N, M;
int W = 0, B = 0;
int wcount = 0, bcount = 0;
queue <pair<int, int> > Wq;
queue <pair<int, int> > Bq;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Wcount(int x, int y){
    visited[x][y] = true;
    Wq.push(make_pair(x,y));
    
    while(!Wq.empty()){
        int tx = Wq.front().first;
        int ty = Wq.front().second;
        Wq.pop();

        for(int i=0; i<4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;

            if(map[nx][ny] == 'W' && !visited[nx][ny]){
                visited[nx][ny] = true;
                Wq.push(make_pair(nx, ny));
                wcount++;
            }
        }
    }

    return wcount * wcount;
}

int Bcount(int x, int y){
    visited[x][y] = true;
    Bq.push(make_pair(x,y));

    while(!Bq.empty()){
        int tx = Bq.front().first;
        int ty = Bq.front().second;
        Bq.pop();

        for(int i=0; i<4; i++){
            int nx = tx + dx[i];
            int ny = ty + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N)
                continue;

            if(map[nx][ny] == 'B' && !visited[nx][ny]){
                visited[nx][ny] = true;
                Bq.push(make_pair(nx, ny));
                bcount++;
            }
        }

    }

    return bcount * bcount;
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            scanf("%1s", &map[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 'W' && !visited[i][j]){
                wcount++;
                W += Wcount(i, j);
            }
            else if(map[i][j] == 'B' && !visited[i][j]){
                bcount++;
                B += Bcount(i, j);
            }
            wcount = 0;
            bcount = 0;
        }
    }

    cout << W << " " << B;
     
}