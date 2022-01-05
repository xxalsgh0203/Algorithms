#include <iostream>
using namespace std;
int N, M, d;
int result = 0;
int robot_x, robot_y; // 로봇의 현재위치
int area[50][50];
int dx[4] = {-1, 0, 1, 0}; // 0:북쪽  1:동쪽  2:남쪽  3:서쪽
int dy[4] = {0, 1, 0, -1};
void Input();
void NoAreatoClean(int);
void Search(int);
void Solve();

void Input(){
    cin >> N >> M;
    cin >> robot_x >> robot_y >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> area[i][j];
        }
    }
}

void NoAreatoClean(int back){
    int back_x, back_y;
    back_x = robot_x + dx[back]; 
    back_y = robot_y + dy[back];
    if(area[back_x][back_y] == 2){ // 후진할수 있으면 한칸 후진
        robot_x = back_x;
        robot_y = back_y;
        Search(0); // 2번으로 돌아감
    }
    else if(area[back_x][back_y] == 1){ // 후진도 못하면
        return;
    }
}

void Search(int cnt){ // 왼쪽부터 차례대로 탐색. 2번

    if(cnt == 4){   // 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
        int back;
        if(d==0){
            back = 2;
            NoAreatoClean(back);
            return;
        }
        else if(d==1){
            back = 3;
            NoAreatoClean(back);
            return;
        }
        else if(d==2){
            back = 0;
            NoAreatoClean(back);
            return;
        }
        else if(d==3){
            back = 1;
            NoAreatoClean(back);
            return;
        }
    }

    int nd;
    if(d==0){ // 왼쪽 방향 바라보게
        nd = 3;
    }
    else if(d==1){  // 왼쪽 방향 바라보게
        nd = 0;
    }
    else if(d==2){  // 왼쪽 방향 바라보게
        nd = 1;
    }
    else if(d==3){  // 왼쪽 방향 바라보게
        nd = 2;
    }

    int nx = robot_x + dx[nd];   // 회전
    int ny = robot_y + dy[nd];

    if(area[nx][ny] == 0){  // 왼쪽 방향에 아직 청소하지 않은 공간이 존재하면
        area[nx][ny] = 2; // 청소를 한후
        result++;
        d = nd; // 그방향으로 회전한다음
        robot_x = nx; // 한칸 전진한후
        robot_y = ny;
        Search(0); // 1번부터 진행
    }
    else{   // 왼쪽 방향에 청소할 수 없는 경우이면
        d = nd; // 그 방향으로 회전하고
        Search(cnt + 1);
    }
}

void Solve(){
    area[robot_x][robot_y] = 2;
    result++;
    Search(0);
    cout << result;
}

int main(){
    Input();
    Solve();
}