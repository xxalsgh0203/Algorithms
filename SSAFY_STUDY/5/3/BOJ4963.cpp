#include <iostream>
#include <queue>
using namespace std;

int map[51][51];
bool visited[51][51];
int h, w;

int dy[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dx[8] = {0, 1, 0, -1, -1, 1, -1, 1};

void Init() {
    for (int i = 0; i < 51; i++) {
        for (int j = 0; j < 51; j++) {
            map[i][j] = -1;
            visited[i][j] = false;
        }
    }
}

bool inRange(int y, int x) {
    if (y >= 0 && x >= 0 && y < h && x < w)
        return true;

    return false;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        visited[cur_y][cur_x] = true;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x) && map[next_y][next_x] == 1) {
                if (!visited[next_y][next_x]) {
                    q.push(make_pair(next_y, next_x));
                    visited[next_y][next_x] = true; // 주의 ! 큐에 넣어줄때 방문처리 해야함. 아니면 여러번 방문할 수 있어 메모리 초과 발생
                }
            }
        }
    }
}

int main() {
    while (1) {
        cin >> w >> h;
        Init();
        if (w == 0 && h == 0)
            break;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        int count = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    count++;
                    BFS(i, j);
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}