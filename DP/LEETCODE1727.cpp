#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    bool comp(int a, int b) {
        return a > b;
    }

    int largestSubmatrix(vector<vector<int>>& matrix){
        int width = matrix.size();
        int height = matrix[0].size();

        for(int i=1; i<width; i++){
            for(int j=0; j<height; j++){
                if(matrix[i][j] != 0)
                    matrix[i][j] += matrix[i-1][j];
            }
        }

        int maxnum = 0;

        for(int i=0; i<width; i++){
            sort(matrix[i].begin(), matrix[i].end());
            for(int j=0; j<height; j++){
                maxnum = max(maxnum, matrix[i][j] * (height - j));
            }
        }

        return maxnum;
    }
};

int main(){
    vector<vector<int> > matrix = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0 ,1}
    };

    Solution A;
    cout << A.largestSubmatrix(matrix);
}