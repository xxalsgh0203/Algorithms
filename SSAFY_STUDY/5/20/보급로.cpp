#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int map[101][101];
int dp[101][101];
int N;

bool inRange(int y, int x) {
    if (y >= 0 && y < N && x >= 0 && x < N)
        return true;

    return false;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x)) {
                int point = dp[cur_y][cur_x] + map[next_y][next_x];
                if (dp[next_y][next_x] > point) {
                    dp[next_y][next_x] = point;
                    q.push(make_pair(next_y, next_x));
                }
            }
        }
    }
}

int main() {
    int TC;
    cin >> TC;

    for (int testcase = 1; testcase <= TC; testcase++) {
        cin >> N;
        // 입력
        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;
            for (int j = 0; j < temp.length(); j++) {
                map[i][j] = temp[j] - '0';
            }
        }

        // 초기화
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[i][j] = 987654321;
            }
        }
        dp[0][0] = 0;

        // 완탐 DP

        BFS(0, 0);

        cout << "#" << testcase << " " << dp[N - 1][N - 1] << '\n';
        memset(map, 0, sizeof(map));
        memset(dp, 987654321, sizeof(dp));
    }
}