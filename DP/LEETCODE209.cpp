#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int dp[32];

    int fib(int n) {
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution A;
    int n;
    cin >> n;
    cout << A.fib(n);
}