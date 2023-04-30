#include <iostream>
#include <queue>
using namespace std;
int N, K;
int Start, End;
int arr[1001];
bool visited[1001];
queue<int> robot;
int empty_space = 0;

void MoveBeltWithRobot() {
    Start--;
    End--;

    if (Start < 1)
        Start = 2 * N;
    if (End < 1)
        End = 2 * N;
}

void MoveRobot() {
    int Size = robot.size();
    for (int i = 0; i < Size; i++) {
        int cur = robot.front();
        visited[cur] = false;
        robot.pop();

        if (cur == End)
            continue;

        int next = cur + 1;
        if (next > 2 * N)
            next = 1;

        if (visited[next] == false && arr[next] >= 1) {
            arr[next]--;
            if (arr[next] == 0)
                empty_space++;
            if (next == End)
                continue;
            visited[next] = true;
            robot.push(next);
        } else {
            robot.push(cur);
            visited[cur] = true;
        }
    }
}

void PushRobot() {
    if (visited[Start] == false && arr[Start] >= 1) {
        visited[Start] = true;
        arr[Start]--;
        robot.push(Start);
        if (arr[Start] == 0) {
            empty_space++;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 1; i <= 2 * N; i++) {
        int belt;
        cin >> belt;
        arr[i] = belt;
    }

    int cnt = 0;
    Start = 1;
    End = N;

    while (empty_space < K) {
        cnt++;
        MoveBeltWithRobot();
        MoveRobot();
        PushRobot();
    }
    cout << cnt;
}