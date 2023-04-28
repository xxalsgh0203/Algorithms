#include <deque>
#include <iostream>
using namespace std;

int main() {
    int N, K, M;
    cin >> N >> K >> M;

    deque<int> result;

    for (int i = 1; i <= N; i++) {
        result.push_back(i);
    }

    bool flag = false;
    int cnt = 0;

    while (!result.empty()) {
        if (!flag) {
            for (int i = 0; i < K - 1; i++) {
                int temp = result.front();
                result.pop_front();
                result.push_back(temp);
            }
            cnt++;
            cout << result.front() << '\n';
            result.pop_front();
        } else if (flag) {
            for (int i = 0; i < K - 1; i++) {
                int temp = result.back();
                result.pop_back();
                result.push_front(temp);
            }
            cnt++;
            cout << result.back() << '\n';
            result.pop_back();
        }
        if (cnt % M == 0) {
            flag = !flag;
        }
    }

    return 0;
}