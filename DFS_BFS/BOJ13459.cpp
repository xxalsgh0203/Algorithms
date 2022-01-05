#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
const int INF = 987654321;
char map[11][11];
bool visited[11][11][11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int red_x, red_y, blue_x, blue_y;

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'B'){
                blue_x = i;
                blue_y = j;
            }
            else if(map[i][j] == 'R'){
                red_x = i;
                red_y = j;
            }
        }
    }
}

void move(int x_dir, int y_dir, int &ball_x, int &ball_y, int &dist){
    while(map[ball_x + x_dir][ball_y + y_dir] != '#' && map[ball_x][ball_y] != 'O'){
        dist += 1;
        ball_x += x_dir;
        ball_y += y_dir;
    }
}

int BFS(){
    queue <pair<int, pair<int, int> > > redball;
    queue <pair<int, pair<int, int> > > blueball;
    redball.push(make_pair(0, make_pair(red_x, red_y)));
    blueball.push(make_pair(0, make_pair(blue_x, blue_y)));
    visited[red_x][red_y][blue_x][blue_y] = true;

    while(!redball.empty() || !blueball.empty()){
        int rx = redball.front().second.first;
        int ry = redball.front().second.second;
        int bx = blueball.front().second.first;
        int by = blueball.front().second.second;
        int rcnt = redball.front().first;
        int bcnt = blueball.front().first;
        redball.pop();
        blueball.pop();

        if(rcnt >= 10 || bcnt >= 10)   break;

        for(int i=0; i<4; i++){
            int nrx = rx, nry = ry;
            int nbx = bx, nby = by;
            int redball_dist = 0;
            int blueball_dist = 0;
            move(dx[i], dy[i], nrx, nry, redball_dist);
            move(dx[i], dy[i], nbx, nby, blueball_dist);

            if(map[nbx][nby] == 'O')    continue; // 파란 구슬이 구멍에 빠지면
            if(map[nrx][nry] == 'O')    return 1; // 빨간 구슬이 구멍에 빠지면
            
            if(nrx == nbx && nry == nby){
                if(redball_dist > blueball_dist){
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else{
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if(visited[nrx][nry][nbx][nby])
                continue;

            visited[nrx][nry][nbx][nby] = true;

            redball.push(make_pair(rcnt+1,make_pair(nrx, nry)));
            blueball.push(make_pair(bcnt+1,make_pair(nbx, nby)));
        }
    }
    return -1;
}

void Solve(){
    int result = BFS();
    if(result == -1)
        cout << "0";
    else if(result == 1)
        cout << "1";
}

int main(){
    Input();
    Solve();
}

