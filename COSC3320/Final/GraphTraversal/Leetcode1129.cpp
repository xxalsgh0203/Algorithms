// https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        dp[0] = nums[0];
        int result = dp[0];
        
        for(int i = 1; i < n; i++){
            dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
            result = max(result, dp[i]);
        }
        
        return result;
    }
};

int main(){
    Solution A;
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(7);
    nums.push_back(8);
    cout << A.maxSubArray(nums);
}