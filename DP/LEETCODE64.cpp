#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(i==0){
                    grid[i][j] += grid[i][j-1];
                    continue;
                }else if(j==0){
                    grid[i][j] += grid[i-1][j];
                    continue;
                }else{
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
                }
            }
        }

        return grid[grid.size()-1][grid[0].size()-1];
    } 
};

int main(){
    vector<vector<int> > grid;
    Solution A;
    cout << A.minPathSum(grid);
}