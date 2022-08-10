#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    bool inRange(int y, int x, int ysize, int xsize){
        if(y<0 || x<0 || y>=ysize || x>=xsize)
            return false;

        return true;
    }

    int DFS(vector<vector<int>>& grid, int y, int x){
        if(y == grid.size()){
            return x;
        }

        if(inRange(y, x, grid.size(), grid[0].size())){
            if(grid[y][x] == 1){    
                if(grid[y][x+1] == 1 && inRange(y, x+1, grid.size(), grid[0].size())){  // can direct ball to right side
                    return DFS(grid, y+1, x+1);
                }
            }
            else{ 
                if(grid[y][x-1] == -1 && inRange(y, x-1, grid.size(), grid[0].size())){ // can direct ball to left side
                    return DFS(grid, y+1, x-1);
                }
            }
        }

        return -1;
    }

    vector<int> findBall(vector<vector<int>>& grid) {
        
        int m = grid.size(); // num of rows
        int n = grid[0].size(); // num of columns

        vector<int> result(n, 0);

        for(int i=0; i<n; i++){
            result[i] = DFS(grid, 0, i);
        }
        
        return result;
    }
};

int main(){
    Solution A;
    vector<vector<int> > grid{
        {1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1},
        {1,1,1,1,1,1},
        {-1,-1,-1,-1,-1,-1}
    };
    vector <int> result;
    result = A.findBall(grid);

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
}