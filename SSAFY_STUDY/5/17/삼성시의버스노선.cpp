#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int N;
        cin >> N;
        int arr[5001];
        vector<pair<int, int>> bus;

        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < N; i++) {
            int start, end;
            cin >> start >> end;
            for (int j = start; j <= end; j++) {
                arr[j]++;
            }
        }

        int P;
        cin >> P;

        vector<int> result;
        for (int i = 0; i < P; i++) {
            int bus_stop;
            cin >> bus_stop;
            result.push_back(arr[bus_stop]);
        }

        cout << "#" << testcase << " ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
}