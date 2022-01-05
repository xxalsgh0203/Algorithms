// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int dp[1000];
//     int Solve(vector<int>& v){
//         dp[0] = v[0];
//         dp[1] = max(v[0], v[1]);
//         for(int i=2; i<v.size(); i++){
//             dp[i] = max(dp[i-1], dp[i-2]+v[i]);
//         }
//         return dp[v.size()-1];
//     }

//     int rob(vector<int>& nums) {
//         vector <int> v1(nums.begin(), nums.end()-1);
//         vector <int> v2(nums.begin()+1, nums.end());

//         if (nums.size() == 0) return 0;
//         if (nums.size() == 1) return nums[0];
//         if (nums.size() == 2) return max(nums[0], nums[1]);

//         return max(Solve(v1), Solve(v2));
//     }
// };

// int main(){
//     vector <int> vec;
//     Solution A;
//     cout << A.rob(vec);
// }

// no error