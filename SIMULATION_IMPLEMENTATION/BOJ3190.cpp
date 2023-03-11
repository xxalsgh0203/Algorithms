#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, K, L; // N : 보드 크기, K : 사과 개수, L : 뱀의 방향 변환 횟수
int apple_map[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int snake[101][101];

vector<pair<int, char>> snake_movement;
void Debugg(int);

void Init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            snake[i][j] = 0;
            apple_map[i][j] = 0;
        }
    }
}

bool inRange(int y, int x) {
    if (y > 0 && x > 0 && x <= N && y <= N) {
        return true;
    }
    return false;
}

int Move(int y, int x) {
    int time = 0;
    int direction = 0;
    int snake_head_y = y;
    int snake_head_x = x;
    int snake_tail_y = y;
    int snake_tail_x = x;
    snake[y][x] = time + 1;

    while (1) {

        // Debugg(time);

        time++;

        if (time - 1 == snake_movement.back().first) {
            if (snake_movement.back().second == 'L') {
                if (direction == 0) {
                    direction = 3;
                } else {
                    direction = (direction - 1) % 4;
                }
            } else {
                direction = (direction + 1) % 4;
            }
            snake_movement.pop_back();
        }

        int next_y = snake_head_y + dy[direction];
        int next_x = snake_head_x + dx[direction];

        if (!inRange(next_y, next_x) || snake[next_y][next_x] > 0) {
            break;
        }

        snake_head_y = next_y;
        snake_head_x = next_x; // 먼저 뱀은 몸길이를 늘려 머리를 다음칸에 위치 시킨다
        snake[snake_head_y][snake_head_x] = time + 1;

        if (apple_map[next_y][next_x] == 1) {        // 다음칸에 사과가 있으면
            apple_map[next_y][next_x] = 0;           // 그 칸에 있던 사과가 없어지고
        } else if (apple_map[next_y][next_x] == 0) { // 사과가 없으면
            for (int i = 0; i < 4; i++) {
                int tail_y = snake_tail_y + dy[i];
                int tail_x = snake_tail_x + dx[i];

                if (snake[snake_tail_y][snake_tail_x] + 1 == snake[tail_y][tail_x]) {
                    snake[snake_tail_y][snake_tail_x] = 0;
                    snake_tail_y = tail_y;
                    snake_tail_x = tail_x;
                    break;
                }
            }
        }
    }

    return time;
}

void Input() {
    cin >> N;
    cin >> K;
    Init();
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        apple_map[y][x] = 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int time;
        char direction;
        cin >> time >> direction;
        snake_movement.push_back(make_pair(time, direction));
    }
}

void Solve() {
    Input();
    sort(snake_movement.rbegin(), snake_movement.rend());
    cout << Move(1, 1);
}

void Debugg(int time) {
    for (int i = 0; i < N; i++) {
        cout << "***";
    }
    cout << '\n';
    cout << time << " 초 경과 : \n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << snake[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < N; i++) {
        cout << "***";
    }
    cout << '\n';
}

int main() {
    Solve();
    return 0;
}