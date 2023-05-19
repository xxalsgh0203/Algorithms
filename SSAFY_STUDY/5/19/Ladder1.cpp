#include <cstring>
#include <iostream>
using namespace std;

bool inRange(int y, int x) {
    if (y >= 0 && x >= 0 && x < 100 && y < 100)
        return true;

    return false;
}

int main() {
    int map[101][101];
    for (int testcase = 1; testcase <= 10; testcase++) {
        int TC;
        cin >> TC;
        // 맵 초기화
        memset(map, 0, sizeof(map));

        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> map[i][j];
            }
        }

        int cur_y = 99;
        int cur_x = 99;

        for (int i = 0; i < 99; i++) {
            if (map[99][i] == 2) {
                cur_x = i;
            }
        }

        int result;

        while (cur_y >= 0) {
            int next_y = cur_y - 1;
            int next_x = cur_x;

            if (map[next_y][next_x - 1] == 1) { // 왼쪽으로 이동 가능하면
                while (map[next_y][next_x - 1] == 1) {
                    next_x--;
                }
            } else if (map[next_y][next_x + 1] == 1) {
                while (map[next_y][next_x + 1] == 1) {
                    next_x++;
                }
            }

            cur_y = next_y;
            cur_x = next_x;

            // cout << cur_y << " " << cur_x << '\n';

            if (cur_y == 0) {
                result = cur_x;
                break;
            }
        }

        cout << "#" << testcase << " " << result << '\n';
    }
}

// 1 0 0 0 1 0 1 0 0 1
// 1 0 0 0 1 0 1 1 1 1
// 1 0 0 0 1 0 1 0 0 1
// 1 0 0 0 1 1 1 0 0 1
// 1 0 0 0 1 0 1 0 0 1
// 1 1 1 1 1 0 1 1 1 1
// 1 0 0 0 1 0 1 0 0 1
// 1 1 1 1 1 0 1 0 0 1
// 1 0 0 0 1 1 1 0 0 1
// 1 0 0 0 1 0 1 0 0 2