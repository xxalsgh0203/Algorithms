#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int dump;
    vector<int> boxes;

    for (int testcase = 1; testcase <= 10; testcase++) {
        cin >> dump;

        for (int i = 0; i < 100; i++) {
            int box;
            cin >> box;
            boxes.push_back(box);
        }

        while (dump != 0) {
            int min_height_index = min_element(boxes.begin(), boxes.end()) - boxes.begin();
            int max_height_index = max_element(boxes.begin(), boxes.end()) - boxes.begin();
            boxes[max_height_index]--;
            boxes[min_height_index]++;
            dump--;
        }

        int result = *max_element(boxes.begin(), boxes.end()) - *min_element(boxes.begin(), boxes.end());

        cout << "#" << testcase << " " << result << '\n';

        boxes.clear();
    }

    return 0;
}