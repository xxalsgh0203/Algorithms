#include <iostream>
#include <vector>
using namespace std;

int main() {
    for (int testcase = 1; testcase <= 10; testcase++) {
        int N;
        string S;
        vector<char> v;
        cin >> N >> S;

        v.push_back(S[0]);

        for (int i = 1; i < N; i++) {
            char c = S[i];

            if (v.back() != S[i]) {
                v.push_back(S[i]);
                // cout << c << " ";
                continue;
            }

            if (v.back() == S[i]) {
                v.pop_back();
            }
        }

        cout << "#" << testcase << " ";
        for (int i = 0; i < v.size(); i++) {
            cout << v[i];
        }
        cout << '\n';
    }
}
