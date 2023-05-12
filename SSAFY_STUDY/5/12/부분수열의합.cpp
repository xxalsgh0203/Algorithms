#include <cstring>
#include <iostream>
using namespace std;

int N, K;
int arr[21];
int result;

void Solve(int index, int sum) {
    if (sum > K)
        return;

    if (sum == K) {
        result++;
        return;
    }

    for (int i = index; i < N; i++) {
        Solve(i + 1, sum + arr[i]);
    }
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {

        // reset
        N = 0;
        K = 0;
        cin >> N >> K;
        result = 0;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solve(0, 0);

        cout << "#" << testcase << " " << result << '\n';
    }
}