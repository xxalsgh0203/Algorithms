#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testcase;
    cin >> testcase;

    for (int tc = 1; tc <= testcase; tc++) {

        vector<int> results;

        string numbers;
        int cnt;
        cin >> numbers >> cnt;

        for (int i = 0; i < numbers.length(); i++) {
            results.push_back(numbers[i] - '0');
        }

        int index = 0;
        int count = 0;

        while (cnt != 0) {
            int max_num = 0;
            int max_index = index;
            // find max value and max index
            for (int i = index; i < results.size(); i++) {
                if (max_num <= results[i]) {
                    max_num = results[i];
                    max_index = i;
                }
            }
            // swap
            int temp = results[index];
            results[index] = max_num;
            results[max_index] = temp;

            index++;
            if (index != max_index)
                cnt--;

            if (index >= results.size() - 1) {
                // 끝에 두개 swap
                int temp_T = results[results.size() - 2];
                results[results.size() - 2] = results[results.size() - 1];
                results[results.size() - 1] = temp_T;
            }
        }

        cout << "#" << tc << " ";
        for (int i = 0; i < results.size(); i++) {
            cout << results[i];
        }
        cout << '\n';
    }
}