#include <iostream>
#include <vector>
using namespace std;
int N, M, dice_x, dice_y, K;
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int map[21][21];
int dice[7] = {0};
vector <int> direction;

void Input(){
    cin >> N >> M >> dice_x >> dice_y >> K;
    for(int i=0; i<N; i++){ // 맵 정보 입력
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<K; i++){
        int dir;
        cin >> dir;
        direction.push_back(dir);
    }
}

void Roll(int direction){
    int d1 = dice[1];
    int d2 = dice[2];
    int d3 = dice[3];
    int d4 = dice[4];
    int d5 = dice[5];
    int d6 = dice[6];

    if(direction == 1){
        dice[1] = d4;
        dice[4] = d6;
        dice[3] = d1;
        dice[6] = d3;
    }
    else if(direction == 2){
        dice[6] = d4;
        dice[4] = d1;
        dice[1] = d3;
        dice[3] = d6;
    }
    else if(direction == 3){
        dice[1] = d5;
        dice[2] = d1;
        dice[6] = d2;
        dice[5] = d6;
    }
    else if(direction == 4){
        dice[1] = d2;
        dice[5] = d1;
        dice[6] = d5;
        dice[2] = d6;
    }
}

bool inRange(int x, int y){
    return x>=0 && y>=0 && x<N && y<M;
}

void Solve(){
    int x = dice_x;
    int y = dice_y;

    for(vector<int>::size_type i=0; i<direction.size(); i++){
        int d = direction[i];
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!inRange(nx, ny))  
            continue; // 주사위는 지도의 바깥으로 이동시킬 수 없다. 만약 바깥으로 이동시키려고 하는 경우에는 해당 명령을 무시해야 하며, 출력도 하면 안 된다.
        
        Roll(d);

        if(map[nx][ny] == 0){ // 이동한 칸에 쓰여 있는 수가 0이면, 주사위의 바닥면에 쓰여 있는 수가 칸에 복사된다
            map[nx][ny] = dice[6];
        }
        else{ // 0이 아닌 경우에는 칸에 쓰여 있는 수가 주사위의 바닥면으로 복사되며, 칸에 쓰여 있는 수는 0이 된다
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }

        cout << dice[1] << '\n';

        x = nx;
        y = ny;
    }
}

int main(){
    Input();
    Solve();
}   