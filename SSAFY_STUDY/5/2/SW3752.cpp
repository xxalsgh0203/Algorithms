#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;
    for (int tc = 0; tc < testcase; tc++) {
        int N;
        vector<int> points;
        bool visited[10001];
        cin >> N;
        for (int i = 0; i < N; i++) {
            int test_result;
            cin >> test_result;
            points.push_back(test_result);
        }

        visited[0] = true;
        vector<int> v;
        v.push_back(0);

        for (int i = 0; i < 10001; i++) {
            visited[i] = false;
        }

        for (int i = 0; i < N; i++) {
            int len = v.size();
            for (int j = 0; j < len; j++) {
                int curr = v[j];
                int next = curr + points[i];
                if (!visited[next]) {
                    v.push_back(next);
                    visited[next] = true;
                }
            }
        }

        cout << "#" << tc + 1 << " " << v.size() << '\n';
    }
}