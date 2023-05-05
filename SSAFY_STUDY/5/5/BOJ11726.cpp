#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[n + 1];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= 10007;
    }

    cout << dp[n];
}