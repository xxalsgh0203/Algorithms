#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int tc = 0; tc < testcase; tc++) {
        int N;
        cin >> N;
        int points[10001];
        bool visited[10001];
        for (int i = 0; i < N; i++) {
            cin >> points[i];
        }

        vector<int> v;
        v.push_back(0);

        for (int i = 0; i < 10001; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < N; i++) {
            int SIZE = v.size();
            for (int j = 0; j < SIZE; j++) {
                int total_point = points[i] + v[j];
                if (!visited[total_point]) {
                    visited[total_point] = true;
                    v.push_back(total_point);
                }
            }
        }

        cout << "#" << tc + 1 << " " << v.size() << '\n';
    }
}