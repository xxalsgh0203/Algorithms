#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool comp (vector<int>&a,vector<int>&b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }

    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        if(intervals.size()==0)
            return 0;

        sort(intervals.begin(), intervals.end(), comp);
        int end = intervals[0][1];
        int cnt = 0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] < end){
                end = min(end, intervals[i][1]);
                cnt++;
            }
            else
                end = intervals[i][1];
        }

        return cnt;
    }
};

int main(){
    vector<vector<int> > intervals;
    Solution A;
    cout << A.eraseOverlapIntervals(intervals);
}