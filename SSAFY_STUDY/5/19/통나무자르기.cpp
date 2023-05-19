#include <iostream>
using namespace std;

int T;

int main() {
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        int N;
        cin >> N;
        cout << "#" << testcase << " ";
        if (N % 2 == 0) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    }
}