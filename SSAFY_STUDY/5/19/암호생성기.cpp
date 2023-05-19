#include <deque>
#include <iostream>
using namespace std;

int main() {
    for (int testcase = 1; testcase <= 10; testcase++) {
        int tc;
        cin >> tc;
        deque<int> dq;
        for (int i = 0; i < 8; i++) {
            int password;
            cin >> password;
            dq.push_back(password);
        }
        int cnt = 1;
        while (dq.front() - cnt > 0) {
            dq.push_back(dq.front() - cnt);
            dq.pop_front();
            cnt++;
            if (cnt > 5)
                cnt = 1;
        }

        dq.pop_front();
        dq.push_back(0);

        cout << "#" << testcase << " ";
        for (int i = 0; i < dq.size(); i++) {
            cout << dq[i] << " ";
        }
        cout << '\n';
    }
}