#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;
        int max_num = -1;
        vector<int> v;
        for (int i = 0; i < N; i++) {
            int number;
            cin >> number;
            v.push_back(number);
        }

        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int value = v[i] * v[j];

                string temp = to_string(value);
                // 단조 증가하는 수인지 확인
                int result = 1;
                bool flag = true;
                for (int k = 1; k < temp.length(); k++) {
                    if ((temp[k] - '0') < (temp[k - 1] - '0')) { // 단조 증가하는 수이면
                        flag = false;
                        break;
                    }
                }

                if (flag) {
                    max_num = max(max_num, value);
                }
            }
        }

        cout << "#" << testcase << " " << max_num << '\n';
    }
}