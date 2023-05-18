#include <cstring>
#include <iostream>
using namespace std;

int map[10][10];

int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

bool isFull(int N) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == 0)
                return false;
        }
    }

    return true;
}

bool inRange(int y, int x, int N) {
    if (y >= 1 && y <= N && x >= 1 && x <= N) {
        return true;
    }

    return false;
}

bool isValid(int y, int x, int N, int color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= N; j++) {
            int next_y = y + dy[i] * j;
            int next_x = x + dx[i] * j;

            if (!inRange(next_y, next_x, N))
                break;

            if (map[next_y][next_x] == 0)
                break;

            if (map[next_y][next_x] == color)
                return true;
        }
    }

    return false;
}

void Update(int y, int x, int N, int color) {
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j <= N; j++) {
            int next_y = y + dy[i] * j;
            int next_x = x + dx[i] * j;

            if (!inRange(next_y, next_x, N))
                continue;

            if (map[next_y][next_x] == 0)
                break;

            if (map[next_y][next_x] == color) {
                for (int k = 1; k <= j; k++) {
                    map[y + dy[i] * k][x + dx[i] * k] = color;
                }
                break;
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int N, M;
        cin >> N >> M;

        memset(map, 0, sizeof(map));

        map[N / 2][N / 2] = 2;
        map[N / 2][N / 2 + 1] = 1;
        map[N / 2 + 1][N / 2] = 1;
        map[N / 2 + 1][N / 2 + 1] = 2;

        for (int i = 0; i < M; i++) {
            int y, x, color;
            cin >> x >> y >> color;
            if (!map[y][x] && isValid(y, x, N, color)) {
                map[y][x] = color;
                Update(y, x, N, color);
            }

            if (isFull(N))
                break;
        }

        int black_cnt = 0;
        int white_cnt = 0;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j] == 1) {
                    black_cnt++;
                } else if (map[i][j] == 2) {
                    white_cnt++;
                }
            }
        }

        cout << "#" << testcase << " " << black_cnt << " " << white_cnt << '\n';
    }

    return 0;
}