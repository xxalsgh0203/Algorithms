#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {
        unsigned long long N;
        cin >> N;
        vector<int> v[1000000001];
        int number = 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 2 * i + 1; j++) {
                v[i].push_back(number);
                number += 2;
            }
        }

        cout << "#" << testcase << " " << v[N - 1][0] << " " << v[N - 1][2 * N - 2] << '\n';
    }
}