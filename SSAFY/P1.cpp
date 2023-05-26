#include <deque>
#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;
        deque<pair<int, int>> dq;
        for (int i = 0; i < N; i++) {
            int location, force;
            cin >> location >> force;
            dq.push_back(make_pair(location, force));
        }

        sort(dq.begin(), dq.end());

        int cur_location = 0;
        int next_location = 0;

        int cnt = 0;

        while (!dq.empty()) {

            if (dq.front().first <= next_location) {
                dq.pop_front();
            } else {
                cur_location = dq.front().first;
                next_location = cur_location + dq.front().second;
                dq.pop_front();
                cnt++;
            }
        }

        cout << "#" << testcase << " " << cnt << '\n';
    }
}

// 3
// 1
// 8 2
// 3
// 2 2
// 4 2
// 6 2
// 3
// 2 2
// 50 2
// 98 4