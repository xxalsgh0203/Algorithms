#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int arr[1000001];

int main() {
    int T, N;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {

        cin >> N;

        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        int max_num = arr[0];
        int max_index = 0;

        for (int i = 0; i < N; i++) {
            if (max_num < arr[i]) {
                max_num = arr[i];
                max_index = i;
            }
        }

        long long result = 0;

        for (int i = 0; i < max_index; i++) {
            result += (max_num - arr[i]);
        }

        while (max_index != N - 1) {
            int temp = max_index;
            int start = max_index + 1;
            max_num = arr[start];
            for (int i = start; i < N; i++) {
                if (max_num < arr[i]) {
                    max_num = arr[i];
                    max_index = i;
                }
            }

            for (int i = start; i < max_index; i++) {
                result += (max_num - arr[i]);
            }

            if (max_index == temp)
                break;
        }

        cout << "#" << testcase + 1 << " " << result << '\n';
    }
}