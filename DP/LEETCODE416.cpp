https : // leetcode.com/problems/partition-equal-subset-sum/description/?envType=study-plan&id=level-2

        class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }

        if (sum % 2)
            return false;

        sum /= 2;

        vector<bool> dp(sum + 1, false);
        dp[0] = true;

        for (auto a : nums)
        {
            for (int i = sum; i >= a; i--)
            {
                dp[i] = dp[i] || dp[i - a];
            }
        }

        return dp[sum];
    }
};