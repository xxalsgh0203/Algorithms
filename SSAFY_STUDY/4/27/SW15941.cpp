#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;
        int result = N * N;
        cout << "#" << testcase << " " << result << '\n';
    }
    return 0;
}