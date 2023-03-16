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

bool BFS(int a, int b) {      // BFS
    queue<pair<int, int>> Q;  // BFS에서 사용할 Queue
    vector<pair<int, int>> V; // 인접한 값들의 위치를 저장할 Vector
    Q.push(make_pair(a, b));
    V.push_back(make_pair(a, b)); // 현재 값은 무조건 넣어주고 시작. (초기사이즈 = 1)
    Visited[a][b] = true;

    while (Q.empty() == 0) {
        int C_Num = Q.front().first;
        int Idx = Q.front().second;
        Q.pop();

        int Left_Idx = Idx - 1;       // 같은 원판의 왼쪽 값
        int Right_Idx = Idx + 1;      // 같은 원판의 오른쪽 값
        int Left_Circle = C_Num - 1;  // 왼쪽 원판의 값
        int Right_Circle = C_Num + 1; // 오른쪽 원판의 값

        if (Left_Idx < 0)
            Left_Idx = M - 1;
        if (Right_Idx >= M)
            Right_Idx = Right_Idx % M;

        if (disks[C_Num][Idx] == disks[C_Num][Left_Idx]) {
            if (Visited[C_Num][Left_Idx] == false) {
                Visited[C_Num][Left_Idx] = true;
                Q.push(make_pair(C_Num, Left_Idx));
                V.push_back(make_pair(C_Num, Left_Idx));
            }
        }
        if (disks[C_Num][Idx] == disks[C_Num][Right_Idx]) {
            if (Visited[C_Num][Right_Idx] == false) {
                Visited[C_Num][Right_Idx] = true;
                Q.push(make_pair(C_Num, Right_Idx));
                V.push_back(make_pair(C_Num, Right_Idx));
            }
        }
        if (Left_Circle > 0) {
            if (disks[C_Num][Idx] == disks[Left_Circle][Idx]) {
                if (Visited[Left_Circle][Idx] == false) {
                    Visited[Left_Circle][Idx] = true;
                    Q.push(make_pair(Left_Circle, Idx));
                    V.push_back(make_pair(Left_Circle, Idx));
                }
            }
        }
        if (Right_Circle <= N) {
            if (disks[C_Num][Idx] == disks[Right_Circle][Idx]) {
                if (Visited[Right_Circle][Idx] == false) {
                    Visited[Right_Circle][Idx] = true;
                    Q.push(make_pair(Right_Circle, Idx));
                    V.push_back(make_pair(Right_Circle, Idx));
                }
            }
        }
    }

    if (V.size() == 1) // 크기가 1이다. = 인접한 값들 중 똑같은 값을 가진 놈이 없다.
    {
        return false;
    } else // 그게 아니면 인접한 값들 중 똑같은 값을 가진 놈이 있다.
    {
        for (int i = 0; i < V.size(); i++) {
            int x = V[i].first;
            int y = V[i].second;
            disks[x][y] = 0;
        }
        return true;
    }
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