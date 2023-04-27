#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int tc;
    cin >> tc;

    for (int testcase = 0; testcase < tc; testcase++) {
        int N;
        cin >> N;
        vector<string> result;
        for (int i = 1; i <= N; i++) {
            string number_in_string = to_string(i);
            result.push_back(number_in_string);
        }

        sort(result.begin(), result.end());

        cout << "#" << testcase + 1 << " ";

        int vector_size = result.size();
        vector_size = min(vector_size, 50);

        for (int i = 0; i < vector_size; i++) {
            cout << result[i] << ".png ";
        }

        cout << '\n';
    }

    return 0;
}