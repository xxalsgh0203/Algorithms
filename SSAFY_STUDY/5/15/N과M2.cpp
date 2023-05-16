#include <iostream>
using namespace std;

int arr[9];
int N, M;

void Solve(int index, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = index; i <= N; i++) {
        arr[cnt] = i;
        Solve(i + 1, cnt + 1);
    }

    return;
}

int main() {

    cin >> N >> M;

    Solve(1, 0);
    return 0;
}