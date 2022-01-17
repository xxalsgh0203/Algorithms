#include <iostream>
using namespace std;

// 1. Linear solution
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         int reachable = 0;
//         int n = nums.size();

//         for(int i=0; i<n; i++){
//             if(i > reachable)
//                 return false;
            
//             reachable = max(reachable, i+nums[i]);
//         }

//         return true;
//     }
// };

class Solution {
public: 
    bool canJump(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 0);

        dp[0] = true;

        for(int i=1; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j] && j+nums[j]>=i){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};