#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;

class Solution {
public:

    int dx[4] = {0,-1,0,1};
    int dy[4] = {-1,0,1,0};

    bool visited[300][300];
    queue <pair<int, int> > q;
    
    void bfs(vector<vector<char> >& grid, int x, int y){

        visited[x][y] = true;
        q.push(make_pair(x,y));

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()){
                    if(grid[nx][ny] == '1' && !visited[nx][ny]){
                        q.push(make_pair(nx, ny));
                        visited[nx][ny] = true;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char> >& grid) {
        int cnt = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    cnt++;
                    bfs(grid, i, j);
                }
            }
        }

        return cnt;
    }
};

int main(){
    // vector<vector<char> > grid = {
    //     {"1","1","1","1","0"},
    //     {"1","1","0","1","0"},
    //     {"1","1","0","0","0"},
    //     {"0","0","0","0","0"}
    // };
    // Solution A;
    // cout << A.numIslands(grid);

}