#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int testcase = 0; testcase < tc; testcase++) {
        long long int N;
        cin >> N;
        priority_queue<long long int, vector<long long int>, greater<long long int>> result;

        for (long long int y = 1; y <= sqrt(N); y++) {
            if (N % y == 0) {
                long long int x = N / y;
                result.push(x + y - 2);
            }
        }

        cout << "#" << testcase + 1 << " " << result.top() << '\n';
    }

    return 0;
}