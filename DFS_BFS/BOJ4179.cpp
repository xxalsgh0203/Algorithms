#include <iostream>
#include <queue>
using namespace std;
int R, C;
char maze[1003][1003];
int F_dist[1003][1003];
int J_dist[1003][1003];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
queue <pair<int, int> > fq;
queue <pair<int, int> > jq;

void MoveF(){   // 불이 퍼지는 경로들과 시간을 계산
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(maze[i][j] == 'F'){   // 초기 불씨가 있는 곳
                fq.push(make_pair(i,j));
                F_dist[i][j] = 1;   // 시간 1로 설정
            }
        }
    }

    while(!fq.empty()){
        int nfx = fq.front().first;
        int nfy = fq.front().second;

        fq.pop();

        for(int i=0; i<4; i++){
            int dfx = nfx + dx[i];
            int dfy = nfy + dy[i];

            if(dfx < 0 || dfy < 0 || dfx >= R || dfy >= C)
                continue;
            if(maze[dfx][dfy] == '#' || F_dist[dfx][dfy])
                continue;

            fq.push(make_pair(dfx, dfy));
            F_dist[dfx][dfy] = F_dist[nfx][nfy] + 1;
        }
    }
}

int MoveJ(){
    MoveF(); // 불을 먼저 확산시킨후 계산한다

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(maze[i][j] == 'J'){
                jq.push(make_pair(i, j));
                J_dist[i][j] = 1;
            }
        }
    }

    while(!jq.empty()){
        int njx = jq.front().first;
        int njy = jq.front().second;
        jq.pop();

        for(int i=0; i<4; i++){
            int djx = njx + dx[i];
            int djy = njy + dy[i];

            if(djx < 0 || djy < 0 || djx >= R || djy >= C)  // 지훈이가 미로 밖으로 벗어나면 탈출에 성공한 것이므로
                return J_dist[njx][njy];    // 지훈이가 미로 밖을 벗어난 지점(시점)의 거리를 리턴한다

            if(maze[djx][djy] == '#' || J_dist[djx][djy])   // 벽이거나 지훈이가 방문했던곳이라면 패쓰
                continue;

            if(J_dist[njx][njy] + 1 >= F_dist[djx][djy] && F_dist[djx][djy])    // 불이 더 빨리 도착했으면 그 경로는 패쓰
                continue;

            jq.push(make_pair(djx, djy));
            J_dist[djx][njy] = J_dist[njx][njy] + 1;
        }
    }

    return -1;
}

int main(){
    cin >> R >> C;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> maze[i][j];
        }
    }

    int result = MoveJ();
    if(result != -1)
        cout << result;
    else
        cout << "IMPOSSIBLE";
}