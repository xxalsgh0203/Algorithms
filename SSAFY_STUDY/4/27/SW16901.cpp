#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;
        int cnt = 0;
        for (int i = -1 * N; i <= N; i++) {
            for (int j = -1 * N; j <= N; j++) {
                if (i * i + j * j <= N * N) {
                    cnt++;
                }
            }
        }
        cout << "#" << testcase << " " << cnt << '\n';
    }
    return 0;
}