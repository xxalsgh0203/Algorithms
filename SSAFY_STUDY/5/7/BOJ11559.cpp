#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

char map[12][6];
bool visited[12][6];
bool flag = true;
vector<pair<int, int>> same_puyos;
vector<pair<int, int>> will_be_destroyed;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Gravity() {
    vector<char> temp;
    for (int x = 0; x < 6; x++) {
        temp.clear();
        for (int y = 11; y >= 0; y--) {
            if (map[y][x] != '.') {
                temp.push_back(map[y][x]);
            }
        }
        for (int i = 0; i < temp.size(); i++) {
            map[11 - i][x] = temp[i];
        }
        for (int i = 11 - temp.size(); i >= 0; i--) {
            map[i][x] = '.';
        }
    }
}

bool inRange(int y, int x) {
    if (y >= 0 && y < 12 && x >= 0 && x < 6)
        return true;

    else
        return false;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    char puyo = map[y][x];

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        same_puyos.push_back(make_pair(cur_y, cur_x));

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x) && !visited[next_y][next_x]) {
                if (map[next_y][next_x] == puyo) {
                    visited[next_y][next_x] = true;
                    q.push(make_pair(next_y, next_x));
                }
            }
        }
    }
}

void Destroy() {
    for (int i = 0; i < will_be_destroyed.size(); i++) {
        int y = will_be_destroyed[i].first;
        int x = will_be_destroyed[i].second;

        map[y][x] = '.';
    }
}

void Debugg() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cout << map[i][j] << " ";
        }
        cout << '\n';
    }

    cout << '\n';
    cout << '\n';
}

int main() {

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }

    int cnt = 0;

    while (flag) {
        will_be_destroyed.clear();
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.' && !visited[i][j]) {
                    BFS(i, j);

                    memset(visited, false, sizeof(visited));

                    if (same_puyos.size() >= 4) {
                        for (int k = 0; k < same_puyos.size(); k++) {
                            will_be_destroyed.push_back(same_puyos[k]);
                        }
                    }

                    same_puyos.clear();
                }
            }
        }

        if (will_be_destroyed.size() >= 4) {
            Destroy();
            Gravity();
            cnt++;
            // Debugg();
        } else {
            break;
        }
    }

    cout << cnt;

    return 0;
}