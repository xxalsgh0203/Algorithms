#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 9901;
int dp[100001][3];

int main(){
    int N;
    cin >> N;

    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    
    for(int i=2; i<=N; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % MOD;
    }

    int answer = dp[N][0] + dp[N][1] + dp[N][2];
    cout << answer % MOD;
}
