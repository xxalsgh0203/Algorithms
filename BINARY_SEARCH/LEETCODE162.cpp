#include <iostream>
#include <vector>
using namespace std;

 class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        int left = 0;
        int right = num.size()-1;
        while(left<right){
            int mid = (right+left)/2;
            if(num[mid]<num[mid+1]){
                left = mid+1;
            }
            else right = mid;
        }
        return right;
    }
};

int main(){

    vector <int> num;
    Solution A;
    cout << A.findPeakElement(num);

}