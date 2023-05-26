#include <cstring>
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int map[21][21];
bool visited[21][21];
int dice[7] = {0, 1, 2, 3, 4, 5, 6};
int N, M, K;

bool inRange(int y, int x) {
    if (y >= 1 && y <= N && x >= 1 && x <= M) {
        return true;
    }

    return false;
}

void moveDice(int direction) {
    int dice_1 = dice[1];
    int dice_2 = dice[2];
    int dice_3 = dice[3];
    int dice_4 = dice[4];
    int dice_5 = dice[5];
    int dice_6 = dice[6];

    if (direction == 0) { // →
        dice[1] = dice_4;
        dice[3] = dice_1;
        dice[4] = dice_6;
        dice[6] = dice_3;
    } else if (direction == 1) { // ↓
        dice[1] = dice_2;
        dice[2] = dice_6;
        dice[5] = dice_1;
        dice[6] = dice_5;
    } else if (direction == 2) { // ←
        dice[1] = dice_3;
        dice[3] = dice_6;
        dice[4] = dice_1;
        dice[6] = dice_4;
    } else { // ↑
        dice[1] = dice_5;
        dice[2] = dice_1;
        dice[5] = dice_6;
        dice[6] = dice_2;
    }
}

int result = 0;

void Solve() {
    int cur_y = 1;
    int cur_x = 1;
    int dir = 0;
    while (K != 0) {
        int next_y = cur_y + dy[dir];
        int next_x = cur_x + dx[dir];

        if (inRange(next_y, next_x)) {
            moveDice(dir);
        } else { // 이동방향에 칸이 없다면 이동 방향을 반대로 한 다음 한 칸 굴러간다.
            if (dir == 2) {
                dir = 0;
            } else if (dir == 3) {
                dir = 1;
            } else if (dir == 0) {
                dir = 2;
            } else {
                dir = 3;
            }
            moveDice(dir);
        }

        cur_y = cur_y + dy[dir];
        cur_x = cur_x + dx[dir];

        if (dice[6] > map[cur_y][cur_x]) { // A > B 인 경우
            dir = (dir + 1) % 4;
        } else if (dice[6] < map[cur_y][cur_x]) { // A < B 인 경우
            if (dir == 0)
                dir = 3;
            else {
                dir = dir - 1;
            }
        }

        queue<pair<int, int>> q;
        q.push(make_pair(cur_y, cur_x));
        visited[cur_y][cur_x] = true;

        int cnt = 1;
        int available_spot = map[cur_y][cur_x];

        while (!q.empty()) {
            int q_cur_y = q.front().first;
            int q_cur_x = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int q_next_y = q_cur_y + dy[i];
                int q_next_x = q_cur_x + dx[i];

                if (inRange(q_next_y, q_next_x) && map[q_next_y][q_next_x] == available_spot) {
                    if (!visited[q_next_y][q_next_x]) {
                        visited[q_next_y][q_next_x] = true;
                        q.push(make_pair(q_next_y, q_next_x));
                        cnt++;
                    }
                }
            }
        }
        result += (cnt * available_spot);
        memset(visited, false, sizeof(visited));
        K--;
    }
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    Solve();

    cout << result;

    return 0;
}