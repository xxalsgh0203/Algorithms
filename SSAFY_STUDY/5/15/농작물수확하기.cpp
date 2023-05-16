#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;

        vector<string> map;
        for (int i = 0; i < N; i++) {
            string plants;
            cin >> plants;
            map.push_back(plants);
        }

        int temp = map.size() / 2;
        int result = 0;

        int start = temp;
        int end = temp;

        for (int i = 0; i <= map.size() / 2; i++) {
            for (int j = start; j <= end; j++) {
                int number = map[i][j] - '0';
                result += number;
            }
            start--;
            end++;
        }

        start = 1;
        end = map[temp].length() - 2;

        for (int i = map.size() / 2 + 1; i < map.size(); i++) {
            for (int j = start; j <= end; j++) {
                int number = map[i][j] - '0';
                result += number;
            }
            start++;
            end--;
        }

        cout << "#" << testcase << " " << result << '\n';
    }
}
