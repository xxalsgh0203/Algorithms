#include <cstring>
#include <iostream>
using namespace std;

int N, K;
int arr[21];
int cnt = 0;

void Combinations(int index, int totalsum) {
    if (totalsum == K) {
        cnt++;
        return;
    }

    if (totalsum > K)
        return;

    for (int i = index; i < N; i++) {
        Combinations(i + 1, arr[i] + totalsum);
    }
}

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {

        cin >> N >> K;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Combinations(0, 0);

        cout << "#" << testcase << " " << cnt << '\n';
        memset(arr, 0, sizeof(arr));
        cnt = 0;
    }
}