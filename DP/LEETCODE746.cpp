#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp = cost;
        int n = cost.size();
        for(int i=2; i<n; i++){
            dp[i] = min(dp[i-2] + cost[i], dp[i-1] + cost[i]);
        }

        return min(dp[n-1], dp[n-2]);
    }
};