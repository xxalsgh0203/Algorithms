#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int fixed_seats_cnt;
    bool arr[41];
    int dp[41];
    cin >> fixed_seats_cnt;
    int result = 1;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 1; i <= n; i++) {
        arr[i] = false;
    }
    for (int i = 0; i < fixed_seats_cnt; i++) {
        int seat;
        cin >> seat;
        arr[seat] = true;
    }
    arr[n + 1] = true;
    int cnt = 0;
    for (int i = 1; i <= n + 1; i++) {
        if (!arr[i]) {
            cnt++;
        } else {
            result *= dp[cnt];
            cnt = 0;
        }
    }

    cout << result;
}
