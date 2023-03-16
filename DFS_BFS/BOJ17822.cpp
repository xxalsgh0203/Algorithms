#include <deque>
#include <iostream>
#include <queue>
#include <string.h>
#include <vector>
using namespace std;

int N, M, T; // N : 원판 개수 , M : 원판에 있는 정수의 개수 , T : 원판 회전 횟수
vector<deque<int>> disks(51);
bool Visited[51][51];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Debugg();
bool BFS(int, int);

void Rotate(int x, int d, int k) {
    if (d == 0) { // 시계 방향
        for (int i = x; i <= N; i += x) {
            for (int j = 0; j < k; j++) {
                int first = disks[i].front();
                int last = disks[i].back();

                disks[i].pop_back();
                disks[i].push_front(last);
            }
        }
    } else if (d == 1) { // 반시계 방향
        for (int i = x; i <= N; i += x) {
            for (int j = 0; j < k; j++) {
                int first = disks[i].front();
                int last = disks[i].back();

                disks[i].pop_front();
                disks[i].push_back(first);
            }
        }
    }

    // Debugg();
}

void Check() {
    memset(Visited, false, sizeof(Visited));
    bool flag = false;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            if (!Visited[i][j] && disks[i][j] != 0) {
                bool isChecked = BFS(i, j);
                if (isChecked == true)
                    flag = true;
            }
        }
    }

    if (flag == false) {
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                sum += disks[i][j];
                if (disks[i][j] != 0)
                    count++;
            }
        }

        double average = (double)sum / (double)count;

        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < M; j++) {
                if (disks[i][j] == 0)
                    continue;
                if ((double)(disks[i][j]) > average) {
                    disks[i][j]--;
                } else if ((double)(disks[i][j]) < average) {
                    disks[i][j]++;
                }
            }
        }
    }

    // Debugg();
}

bool BFS(int y, int x) {     // BFS
    queue<pair<int, int>> Q; // BFS에서 사용할 Queue
    Q.push(make_pair(y, x));
    Visited[y][x] = true;
    int numSearch = disks[y][x];
    int flag = false;

    while (!Q.empty()) {
        int cur_y = Q.front().first;
        int cur_x = Q.front().second;
        Q.pop();

        if (cur_y == 1) {

            for (int i = 1; i < 4; i++) {
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if (next_x == -1) {
                    next_x = M - 1;
                } else {
                    next_x = next_x % M;
                }
                if (disks[next_y][next_x] == numSearch && !Visited[next_y][next_x]) {
                    Q.push(make_pair(next_y, next_x));
                    Visited[next_y][next_x] = true;
                    disks[cur_y][cur_x] = 0;
                    disks[next_y][next_x] = 0;
                    flag = true;
                }
            }

        } else if (cur_y == N) {
            for (int i = 0; i < 4; i++) {
                if (i == 2)
                    continue;
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if (next_x == -1) {
                    next_x = M - 1;
                } else {
                    next_x = next_x % M;
                }
                if (disks[next_y][next_x] == numSearch && !Visited[next_y][next_x]) {
                    Q.push(make_pair(next_y, next_x));
                    Visited[next_y][next_x] = true;
                    disks[cur_y][cur_x] = 0;
                    disks[next_y][next_x] = 0;
                    flag = true;
                }
            }

        } else {
            for (int i = 0; i < 4; i++) {
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if (next_x == -1) {
                    next_x = M - 1;
                } else {
                    next_x = next_x % M;
                }
                if (disks[next_y][next_x] == numSearch && !Visited[next_y][next_x]) {
                    Q.push(make_pair(next_y, next_x));
                    Visited[next_y][next_x] = true;
                    disks[cur_y][cur_x] = 0;
                    disks[next_y][next_x] = 0;
                    flag = true;
                }
            }
        }
    }

    return flag;
}

int Calculate() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            sum += disks[i][j];
        }
    }

    return sum;
}

void Input_Solve() {
    cin >> N >> M >> T;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int disk;
            cin >> disk;
            disks[i].push_back(disk);
        }
    }

    for (int i = 0; i < T; i++) {
        int x, d, k;
        cin >> x >> d >> k; // x의 배수인 원판을 d 의 방향으로 k 칸 회전 시킨다
        Rotate(x, d, k);
        Check();
    }
}

void Debugg() {

    for (int j = 0; j < M * 2; j++) {
        cout << '*';
    }

    cout << '\n';

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            cout << disks[i][j] << " ";
        }
        cout << '\n';
    }

    for (int j = 0; j < M * 2; j++) {
        cout << '*';
    }

    cout << '\n';
}

void Solution() {
    Input_Solve();
    cout << Calculate();
}

int main() {
    Solution();
    return 0;
}