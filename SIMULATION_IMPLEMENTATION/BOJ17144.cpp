#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int room[50][50];
int R, C, T;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector <pair<int, int> > aircleaner;
queue <pair<int, int> > dust;

void Input(){
    cin >> R >> C >> T;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> room[i][j];
            if(room[i][j] == -1)
                aircleaner.push_back(make_pair(i,j));
        }
    }
}

bool inRange(int x, int y){
    return x>=0 && y>=0 && x<R && y<C;
}

void Spread(){
    int copied_room[50][50];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            copied_room[i][j] = room[i][j];
        }
    }

    while(!dust.empty()){
        int x = dust.front().first;
        int y = dust.front().second;
        dust.pop();
        int value = room[x][y] / 5;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(room[nx][ny] != -1){
                if(inRange(nx, ny)){
                    copied_room[nx][ny] += value;
                    copied_room[x][y] -= value;
                }
            }
        }
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            room[i][j] = copied_room[i][j];
        }
    }
}

void Clean(){
    for (int Idx = 0; Idx < 2; Idx++)
    {
        if (Idx == 0)
        {
            // 1. 공기청정기 위에서부터 (0, 0)까지 모든 값 떙겨주기
            for (int i = aircleaner[Idx].first - 1; i > 0; i--)
            {
                room[i][0] = room[i - 1][0];
            }
            // 2. 가장 윗줄 땡겨주기
            for (int i = 0; i < C - 1; i++)
            {
                room[0][i] = room[0][i + 1];
            }
            // 3. 반대편 세로라인 땡겨주기
            for (int i = 1; i <= aircleaner[Idx].first; i++)
            {
                room[i - 1][C - 1] = room[i][C - 1];
            }
            // 4. 공기청정기 라인 땡겨주기
            for (int i = C - 1; i > 1; i--)
            {
                room[aircleaner[Idx].first][i] = room[aircleaner[Idx].first][i - 1];
            }
            room[aircleaner[Idx].first][1] = 0;
        }
        else
        {
            for (int i = aircleaner[Idx].first + 1; i < R - 1; i++)
            {
                room[i][0] = room[i + 1][0];
            }
            for (int i = 0; i < C - 1; i++)
            {
                room[R - 1][i] = room[R - 1][i + 1];
            }
            for (int i = R - 1; i >= aircleaner[Idx].first; i--)
            {
                room[i][C - 1] = room[i - 1][C - 1];
            }
            for (int i = C - 1; i > 1; i--)
            {
                room[aircleaner[Idx].first][i] = room[aircleaner[Idx].first][i - 1];
            }
            room[aircleaner[Idx].first][1] = 0;
        }
    }
}

void afterOneSec(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(room[i][j] > 0)
                dust.push(make_pair(i,j));
        }
    }
    Spread();
    Clean();
}

void Solve(){
    int result = 0;
    for(int i=0; i<T; i++){
        afterOneSec();
    }

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(room[i][j] > 0)
                result += room[i][j];
        }
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}

// 1. 맵에 대한 정보를 입력받는다
// 2. 미세먼지의 좌표를 큐에 넣는다
// 3. 미세먼지가 확산된다
// 4. 공기청정기가 작동한다
// 5. 이과정을 t번 반복후에 남은 미세먼지양을 모두 더한다.