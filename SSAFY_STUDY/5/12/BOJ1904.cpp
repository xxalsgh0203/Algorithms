#include <iostream>
using namespace std;

int main() {
    // N = 1  )) 1
    // N = 2  )) 11 00
    // N = 3  )) 111 100 001
    // N = 4  )) 1111 1001 1100 0011 0000
    // N = 5  )) 11100 10000 00100 11111 00001 00111 10011 11001

    long long int N;
    cin >> N;

    long long int dp[1000001];

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }

    cout << dp[N] % 15746;
}