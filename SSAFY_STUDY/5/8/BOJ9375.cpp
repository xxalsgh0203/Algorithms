#include <iostream>
#include <map>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    for (int testcase = 0; testcase < tc; testcase++) {
        int n;
        cin >> n;
        map<string, int> m;
        for (int i = 0; i < n; i++) {
            string cloth1, catalog;
            cin >> cloth1 >> catalog;
            if (m.find(catalog) == m.end()) {
                m.insert({catalog, 1});
            } else {
                m[catalog]++;
            }
        }

        int result = 1;

        for (auto i : m) {
            result *= (i.second + 1);
        }

        cout << result - 1; // 다 안입는 경우
    }
}