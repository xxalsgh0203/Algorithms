#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> numbers;
    numbers.push_back({1, 1, 1, 1, 1, 1, 0}); // 0
    numbers.push_back({0, 0, 0, 0, 1, 1, 0}); // 1
    numbers.push_back({1, 0, 1, 1, 0, 1, 1}); // 2
    numbers.push_back({1, 0, 0, 1, 1, 1, 1}); // 3
    numbers.push_back({0, 1, 0, 0, 1, 1, 1}); // 4
    numbers.push_back({1, 1, 0, 1, 1, 0, 1}); // 5
    numbers.push_back({1, 1, 1, 1, 1, 0, 1}); // 6
    numbers.push_back({1, 1, 0, 0, 1, 1, 0}); // 7
    numbers.push_back({1, 1, 1, 1, 1, 1, 1}); // 8
    numbers.push_back({1, 1, 0, 1, 1, 1, 1}); // 9
    numbers.push_back({0, 0, 0, 0, 0, 0, 0}); // null

    int test_case;
    cin >> test_case;

    for (int tc = 0; tc < test_case; tc++) {
        string A, B;
        cin >> A >> B;

        vector<int> before;
        vector<int> after;

        // cout << A.length() << " " << B.length();

        if (A.length() < 5) {
            int temp = 5 - A.length();
            for (int i = 0; i < temp; i++) {
                before.push_back(10);
            }
            for (int i = 0; i < A.length(); i++) {
                before.push_back(A[i] - '0');
            }
        } else {
            for (int i = 0; i < A.length(); i++) {
                before.push_back(A[i] - '0');
            }
        }

        if (B.length() < 5) {
            int temp = 5 - B.length();
            for (int i = 0; i < temp; i++) {
                after.push_back(10);
            }
            for (int i = 0; i < B.length(); i++) {
                after.push_back(B[i] - '0');
            }
        } else {
            for (int i = 0; i < B.length(); i++) {
                after.push_back(B[i] - '0');
            }
        }

        // for (int i = 0; i < before.size(); i++) {
        //     cout << before[i] << " ";
        // }
        // cout << '\n';
        // for (int i = 0; i < after.size(); i++) {
        //     cout << after[i] << " ";
        // }
        // cout << '\n';

        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                if (numbers[before[i]][j] != numbers[after[i]][j]) {
                    cnt++;
                }
            }
        }

        cout << cnt << '\n';
    }
}