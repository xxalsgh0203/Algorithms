#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int A[52][52];
bool visited[52][52];
// ←, ↖, ↑, ↗, →, ↘, ↓, ↙
int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

vector<pair<int, int>> cur_cloud;

int modifyLocation(int location) {
    if (location == 0) {
        return N;
    }

    if (location == N + 1) {
        return 1;
    }

    return location;
}

void MoveCloud(int d, int s) {

    vector<pair<int, int>> temp_cur_cloud = cur_cloud;
    cur_cloud.clear();

    for (int i = 0; i < temp_cur_cloud.size(); i++) {
        int cur_cloud_y = temp_cur_cloud[i].first;
        int cur_cloud_x = temp_cur_cloud[i].second;

        int next_cloud_y = cur_cloud_y;
        int next_cloud_x = cur_cloud_x;

        for (int j = 0; j < s; j++) {
            next_cloud_y += dy[d];
            next_cloud_x += dx[d];
            next_cloud_y = modifyLocation(next_cloud_y);
            next_cloud_x = modifyLocation(next_cloud_x);
        }

        cur_cloud.push_back(make_pair(next_cloud_y, next_cloud_x));
    }
}

bool inRange(int y, int x) {
    if (y >= 1 && x >= 1 && y <= N && x <= N) {
        return true;
    } else
        return false;
}

void Magic() {

    vector<pair<int, int>> temp_cur_cloud;
    temp_cur_cloud = cur_cloud;

    // 2. 각 구름에서 비가 내려 구름이 있는 칸의 바구니에 저장된 물의 양이 1 증가한다
    for (int i = 0; i < cur_cloud.size(); i++) {
        A[cur_cloud[i].first][cur_cloud[i].second]++;
        visited[cur_cloud[i].first][cur_cloud[i].second] = true;
    }

    // 3. 구름이 모두 사라진다
    cur_cloud.clear();

    // 4. 2에서 물이 증가한 칸 (r,c) 에 물복사 마법 시전한다.
    // 물복사 마법 사용하면, 대각선 방향으로 거리가 1인 칸에 물이 있는 바구니 수만큼 (r,c) 에 있는 바구니의 물의 양이 증가한다.
    for (int i = 0; i < temp_cur_cloud.size(); i++) {
        int count = 0;
        int cur_y = temp_cur_cloud[i].first;
        int cur_x = temp_cur_cloud[i].second;
        for (int i = 2; i <= 8; i += 2) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (inRange(next_y, next_x && A[next_y][next_x] > 0)) {
                count++;
            }
        }
        A[cur_y][cur_x] += count;
    }

    // 바구니에 저장된 물의 양이 2 이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다. 이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (A[i][j] >= 2 && !visited[i][j]) {
                cur_cloud.push_back((make_pair(i, j)));
                A[i][j] -= 2;
            }
        }
    }
}

void initCloud() {
    cur_cloud.push_back(make_pair(N, 1));
    cur_cloud.push_back(make_pair(N, 2));
    cur_cloud.push_back(make_pair(N - 1, 1));
    cur_cloud.push_back(make_pair(N - 1, 2));
}

int Count() {
    int water_amount = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            water_amount += A[i][j];
        }
    }

    return water_amount;
}

void Input_Solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            visited[i][j] = false;
        }
    }

    initCloud();

    for (int i = 0; i < M; i++) {
        int d, s;
        cin >> d >> s;
        // 1. 모든 구름이 di 방향으로 si칸 이동한다.
        MoveCloud(d, s);
        Magic();
        memset(visited, false, sizeof(visited));
    }

    cout << Count();
}

int main() {
    Input_Solve();
    return 0;
}