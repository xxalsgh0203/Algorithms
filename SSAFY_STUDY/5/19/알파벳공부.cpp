#include <iostream>
using namespace std;

int main() {
    int TC;
    string alph = "abcdefghijklmnopqrstuvwxyz";
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {
        string temp;
        cin >> temp;

        int cnt = 0;
        int i = 0, j = 0;

        while (1) {
            if (alph[i] == temp[j]) {
                cnt++;
                i++;
                cout << temp[j] << " ";
            } else {
                j++;
            }

            if (i == alph.length() || j == temp.length())
                break;
        }

        cout << "#" << testcase << " " << cnt << '\n';
    }
}

// abcdefghijklmnopqrstuvwzyx