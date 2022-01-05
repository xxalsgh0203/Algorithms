#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 1;
        int right = nums.size() - 2;
        while(left<=right){
            int middle = (left + right) / 2;
            if(nums[middle] < nums[middle+1] && nums[middle-1] > nums[middle+1] )
                return nums[middle];
            if(nums[middle] > nums[right]){
                left = middle + 1;
            }
            else
                right = middle - 1;
        }
        return min(nums[0], nums[nums.size()-1]);
    }
};

int main(){
    vector<int> nums;
    Solution A;
    cout << A.findMin(nums);
}