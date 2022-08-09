#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> result;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        int xmove_cnt = matrix.size();
        int ymove_cnt = matrix[0].size();

        int cur_x = 0;
        int cur_y = -1;

        vector<int> nSteps{ymove_cnt, xmove_cnt-1};

        int cnt = 0;

        while(nSteps[cnt%2]){
            
            if(cnt == 0){
                for(int i=0; i<nSteps[cnt%2]; i++){
                    cur_x = cur_x + dx[cnt];
                    cur_y = cur_y + dy[cnt];
                    // cout << cur_x << " " << cur_y << " ";
                    result.push_back(matrix[cur_x][cur_y]);
                }
                // cout << '\n';

            }
            else if(cnt == 1){
                for(int i=0; i<nSteps[cnt%2]; i++){
                    cur_x = cur_x + dx[cnt];
                    cur_y = cur_y + dy[cnt];
                    // cout << cur_x << " " << cur_y << " ";
                    result.push_back(matrix[cur_x][cur_y]);
                }
                // cout << '\n';
            }
            else if(cnt == 2){
                for(int i=0; i<nSteps[cnt%2]; i++){
                    cur_x = cur_x + dx[cnt];
                    cur_y = cur_y + dy[cnt];
                    // cout << cur_x << " " << cur_y << " ";
                    result.push_back(matrix[cur_x][cur_y]);
                }
                // cout << '\n';
            }
            else if(cnt == 3){
                for(int i=0; i<nSteps[cnt%2]; i++){
                    cur_x = cur_x + dx[cnt];
                    cur_y = cur_y + dy[cnt];
                    // cout << cur_x << " " << cur_y << " ";
                    result.push_back(matrix[cur_x][cur_y]);
                }
                // cout << '\n';
            }

            nSteps[cnt%2]--;
            cnt = (cnt + 1) % 4;
        }

        return result;
    }
};

int main(){
    Solution A;
    vector <int> result;
    vector<vector<int> > matrix
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    result = A.spiralOrder(matrix);

    // cout << "[ ";

    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    // cout << "]";
}