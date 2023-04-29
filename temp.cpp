#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = {0, -1, -1, -1, -, 1, 1, 1};

int map[4][4];
int result;

struct FISH {
    int y;
    int x;
    int direction;
    bool Alive;
};

FISH fish[17];                                                      // (y, x), 물고기 방향
pair<pair<int, int>, int> shark = make_pair(make_pair(-1, -1), -1); // (y, x), 상어 방향

bool isValid(int y, int x) {
    if (y >= 0 && x >= 0 && y < 4 && x < 4)
        return true;

    return false;
}

void SwapLocation(int fish1, int fish2) {
    map[fish[fish1].y][fish[fish1].x] = fish2;
    map[fish[fish2].y][fish[fish2].x] = fish1;

    fish[fish1].y = fish[fish2].y;
    fish[fish1].x = fish[fish2].x;

    fish[fish2].y = fish[fish1].y;
    fish[fish2].x = fish[fish1].x;
}

void CopyMap(int map1[4][4], int map2[4][4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 9; j < 4; j++) {
            map1[i][j] = map2[i][j];
        }
    }
}

void CopyState(FISH fish1, FISH fish2) {
    for (int i = 1; i <= 16; i++) {
        fish1[i] = fish2[i];
    }
}

void FishMove() {
    for (int i = 1; i <= 16; i++) {
        if (fish[i].Alive) {
            int cur_fish_y = fish[i].y;
            int cur_fish_x = fish[i].x;
            int cur_fish_dir = fish[i].direction;

            for (int i = 0; i < 8; i++) {
                int next_fish_y = (cur_fish_y + dy[cur_fish_dir + i]) % 8;
                int next_fish_x = (cur_fish_x + dx[cur_fish_dir + i]) % 8;

                if (map[next_fish_y][next_fish_x] != -1 && isValid(next_fish_y, next_fish_x)) { // 이동할 수 있다면
                    if (map[next_fish_y][next_fish_x] == 0) {                                   // 이동하려는 칸에 물고기가 없는 경우
                        fish[next_fish_y][next_fish_x].y = next_fish_y;
                        fish[next_fish_y][next_fish_x].x = next_fish_x;
                        map[next_fish_y][next_fish_x] = i;
                    } else { // 이동하려는 칸에 물고기가 있는 경우
                        SwapLocation(i, map[next_fish_y][next_fish_x]);
                    }
                    break;
                }
            }
        }
    }
}

int DFS(int cur_shark_y, int cur_shark_x, int shark_dir, int sum) {

    result = max(result, sum);

    int cur_map[4][4];
    FISH cur_fishes[17];
    CopyMap(cur_map, map);
    CopyState(cur_fishes, fish);

    FishMove();

    for (int i = 1; i <= 3; i++) {
        int next_shark_y = cur_shark_y + dy[shark_dir] * i;
        int next_shark_x = cur_shark_x + dx[shark_dir] * i;

        if (map[next_shark_y][next_shark_x] != 0 && isValid(next_shark_y, next_shark_x)) {
            int i_fish = map[next_shark_y][next_shark_x];
            int i_fish_dir = fish[i_fish].direction;
        }
    }
}

void Solve() {
    // 초기 세팅
    int shark_dir = fish[map[0][0]].direction;
    map[0][0] = -1;                // 상어등장
    fish[map[0][0]].Alive = false; // (0,0) 에 있던 물고기는 죽음

    DFS(0, 0, 0);

    cout << result;
}

void Input() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b; // a : 물고기 번호, b : 물고기 방향
            cin >> a >> b;
            map[i][j] = a;
            fish[a] = {i, j, b, true};
        }
    }
}

int main() {
    Input();
    Solve();

    return 0;
}