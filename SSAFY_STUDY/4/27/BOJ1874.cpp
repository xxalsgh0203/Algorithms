#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    stack<int> st;
    int n;
    cin >> n;
    vector<char> result;
    vector<int> input(n);
    int number = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (!st.empty() && st.top() == a) {
            st.pop();
            result.push_back('-');
        } else if (number <= a) {

            while (number <= a) {
                st.push(number++);
                result.push_back('+');
            }
            st.pop();
            result.push_back('-');
        } else if (!st.empty() && st.top() > a) {
            cout << "NO";
            return 0;
        }
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << '\n';
    }

    return 0;
}