#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution { // dp going backward
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        for(int i=triangle.size()-2; i>=0; i--){
            for(int j=0; j<triangle[i].size(); j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }

        return triangle[0][0];
    }
};

int main(){
    vector<vector<int> > v;
    Solution A;
    A.minimumTotal(v);
}