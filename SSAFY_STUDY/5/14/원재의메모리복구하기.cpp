#include <iostream>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int testcase = 1; testcase <= TC; testcase++) {
        string number;
        cin >> number;

        int cnt = 0;

        char temp = number[0];
        if (temp == '1')
            cnt++;

        for (int i = 1; i < number.length(); i++) {
            if (number[i] != number[i - 1])
                cnt++;
        }

        cout << "#" << testcase << " " << cnt << '\n';
    }
}