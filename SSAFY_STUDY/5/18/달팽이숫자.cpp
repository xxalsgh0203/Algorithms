#include <cstring>
#include <iostream>
using namespace std;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int T, N;
int map[11][11];
bool inRange(int y, int x) {
    if (y >= 1 && y <= N && x >= 1 && x <= N)
        return true;

    return false;
}

int main() {

    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cin >> N;

        int cur_y = 1;
        int cur_x = 0;
        int cur_dir = 0;
        int index = 1;

        int size = N * N;

        memset(map, 0, sizeof(map));

        while (size >= 0) {
            int next_y = cur_y + dy[cur_dir];
            int next_x = cur_x + dx[cur_dir];

            if (map[next_y][next_x] == 0 && inRange(next_y, next_x)) {
                map[next_y][next_x] = index;
                index++;
                size--;
                cur_y = next_y;
                cur_x = next_x;
            } else {
                cur_dir++;
                if (cur_dir == 4) {
                    cur_dir = 0;
                }
            }

            if (size == 0)
                break;
        }

        cout << "#" << testcase << '\n';
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
        cout << '\n';
    }
}