#include <iostream>
using namespace std;

class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        vector <int> sum(10002);
        
        for(int i=0; i<nums.size(); i++){
            sum[nums[i]] += nums[i];  
        }

        vector<int> dp(10002);

        dp[1] = sum[1];
        dp[2] = max(sum[1], sum[2]);
        for(int i=3; i<10002; i++){
            dp[i] = max(dp[i-2] + sum[i], dp[i-1]);
        }

        return max(dp[10000], dp[9999]);
    }
};
