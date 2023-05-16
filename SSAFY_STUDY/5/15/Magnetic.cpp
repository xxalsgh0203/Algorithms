#include <deque>
#include <iostream>
using namespace std;

int main() {
    for (int tc = 1; tc <= 10; tc++) {
        int N;
        cin >> N;
        deque<int> dq[101];
        int map[101][101];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
            }
        }
        int temp = 0;
        for (int j = N - 1; j >= 0; j--) {
            for (int i = 0; i < N; i++) {
                if (map[i][j] != 0) {
                    dq[temp].push_back(map[i][j]);
                }
            }
            temp++;
        }

        for (int i = 0; i < N; i++) {
            if (!dq[i].empty() && dq[i].front() == 2) {
                while (!dq[i].empty()) {
                    dq[i].pop_front();
                    if (dq[i].front() != 2) {
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < N; i++) {
            if (!dq[i].empty() && dq[i].back() == 1) {
                while (!dq[i].empty()) {
                    dq[i].pop_back();
                    if (!dq[i].empty() && dq[i].back() != 1) {
                        break;
                    }
                }
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < dq[i].size(); j++) {
        //         cout << dq[i][j] << " ";
        //     }
        //     cout << '\n';
        // }

        // cout << '\n';

        int result = 0;

        for (int i = 0; i < N; i++) {
            if (dq[i].size() >= 2) {
                for (int j = 0; j < dq[i].size() - 1; j++) {
                    if (dq[i][j] == 1 && dq[i][j + 1] == 2)
                        result++;
                }
            }
        }

        cout << "#" << tc << " " << result << '\n';
    }
}

// 7
// 1 0 2 0 1 0 1
// 0 2 0 0 0 0 0
// 0 0 1 0 0 1 0
// 0 0 0 0 1 2 2
// 0 0 0 0 0 1 0
// 0 0 2 1 0 2 1
// 0 0 1 2 2 0 2