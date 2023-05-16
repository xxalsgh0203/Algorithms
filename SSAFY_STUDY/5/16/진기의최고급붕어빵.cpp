#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int tc;
    cin >> tc;

    for (int testcase = 1; testcase <= tc; testcase++) {

        int N, M, K;
        cin >> N >> M >> K; // M 초의 시간 동안 K 개의 붕어빵을 만들 수 있다

        int max_time = 0;

        vector<int> boong;

        for (int i = 0; i < N; i++) {
            int people_time;
            cin >> people_time;
            boong.push_back(people_time);
        }

        sort(boong.begin(), boong.end());

        bool flag = true;

        for (int i = 0; i < N; i++) {
            int time = boong[i];

            int cur_amount = (time / M) * K;

            if (cur_amount < i + 1) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << "#" << testcase << " "
                 << "Possible" << '\n';
        } else {
            cout << "#" << testcase << " "
                 << "Impossible" << '\n';
        }
    }
}