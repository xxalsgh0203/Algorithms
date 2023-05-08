#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
char map[26][26];
bool visited[26][26];
vector<int> result;
int N;

bool inRange(int y, int x) {
    if (y >= 0 && x >= 0 && y < N && x < N)
        return true;

    return false;
}

int BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    int cur_cnt = 1;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x) && !visited[next_y][next_x]) {
                if (map[next_y][next_x] == '1') {
                    visited[next_y][next_x] = true;
                    q.push(make_pair(next_y, next_x));

                    cur_cnt++;
                }
            }
        }
    }

    return cur_cnt;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1' && !visited[i][j]) {
                int cnt = BFS(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}