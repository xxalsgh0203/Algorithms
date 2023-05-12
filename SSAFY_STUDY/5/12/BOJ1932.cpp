#include <iostream>
using namespace std;

int triangle[501][501];
int dp[501][501];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cin >> triangle[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[i - 1][j] = max(dp[i][j], dp[i][j + 1]) + triangle[i - 1][j];
        }
    }

    cout << dp[0][0];
}