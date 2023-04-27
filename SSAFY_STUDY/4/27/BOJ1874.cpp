#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> temp;
    vector<char> result;
    int n;
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (temp.top() == number) {
            result.push_back('-');
            temp.pop();
        } else if (number >= cnt) {
            while (number >= cnt) {
                temp.push(cnt++);
                result.push_back('+');
            }
            result.push_back('-');
            temp.pop();
        } else if () {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}