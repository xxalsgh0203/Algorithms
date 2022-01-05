#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set <int> rows, cols;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        for(auto row : rows)
            fill(matrix[row].begin(), matrix[row].end(), 0);
        
        for(auto col : cols){
            for(int i=0; i<matrix.size(); i++){
                matrix[i][col] = 0;
            }
        }

    }
};

int main(){
    vector<vector<int> > matrix;
    Solution A;
    A.setZeros(matrix);
}