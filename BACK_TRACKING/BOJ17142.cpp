#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int N, M;
int map[51][51];
int Time[51][51];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, -1, 0, 1};
vector<pair<int, int>> virus;
bool combination[11];
int result = 987654321;
int empty_places = 0;

void Debugg();

bool inRange(int y, int x) {
    if (y >= 0 && x >= 0 && y < N && x < N)
        return true;

    return false;
}

void BFS() {
    queue<pair<int, int>> Q;
    int infected_places = 0;
    int min_time = 0;

    memset(Time, -1, sizeof(Time));

    for (int i = 0; i < virus.size(); i++) {
        if (combination[i] == true) {
            Q.push(make_pair(virus[i].first, virus[i].second));
            Time[virus[i].first][virus[i].second] = 0;
        }
    }

    while (!Q.empty()) {
        int cur_y = Q.front().first;
        int cur_x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x)) {
                if (map[next_y][next_x] != 1 && Time[next_y][next_x] == -1) {
                    Time[next_y][next_x] = Time[cur_y][cur_x] + 1;
                    if (map[next_y][next_x] == 0) {
                        infected_places++;
                        min_time = max(min_time, Time[next_y][next_x]);

                        if (infected_places == empty_places) {
                            result = min(min_time, result);
                            return;
                        }
                    }

                    Q.push(make_pair(next_y, next_x));
                }
            }
        }
    }

    if (infected_places == empty_places)
        result = min(min_time, result);
}

void Solve(int idx, int cnt) {
    if (cnt == M) {
        BFS();
        // Debugg();
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        if (!combination[i]) {
            combination[i] = true;
            Solve(i + 1, cnt + 1);
            combination[i] = false;
        }
    }
}

void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus.push_back(make_pair(i, j));
            }
            if (map[i][j] == 0)
                empty_places++;
        }
    }
}

void Debugg() {
    for (int i = 0; i < 2 * N; i++) {
        cout << "*";
    }
    cout << '\n';

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << Time[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < 2 * N; i++) {
        cout << "*";
    }
    cout << '\n';
}

int main() {
    Input();
    Solve(0, 0);

    if (result == 987654321)
        cout << "-1";
    else
        cout << result;

    return 0;
}