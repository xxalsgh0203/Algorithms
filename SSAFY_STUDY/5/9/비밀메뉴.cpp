#include <iostream>
using namespace std;

int main() {
    int K, M, N;
    cin >> M >> N >> K;
    int secret[101];
    int user[101];
    for (int i = 0; i < M; i++) {
        cin >> secret[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> user[i];
    }

    int flag = false;
    for (int i = 0; i <= N - M; i++) {
        for (int j = 0; j < M; j++) {
            if (user[i + j] == secret[j]) {
                flag = true;
            } else {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "secret";
            return 0;
        }
    }

    cout << "normal";
    return 0;
}