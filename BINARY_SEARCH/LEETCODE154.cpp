// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// using namespace std;

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         set <int> s(nums.begin(), nums.end());
//         nums.assign(s.begin(), s.end());
//         int left = 1;
//         int right = nums.size()-2;
//         while(left<=right){
//             int middle = (left + right) / 2;
//             if(nums[middle] < nums[middle+1] && nums[middle-1] > nums[middle+1] )
//                 return nums[middle];
//             if(nums[middle] > nums[right]){
//                 left = middle + 1;
//             }
//             else
//                 right = middle - 1;
//         }

//         return min(nums[0], nums[nums.size()-1]);
//     }
// };

// int main(){
//     vector <int> v = {1,3,5};
//     Solution A;
//     cout << A.findMin(v);
// }