#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int result = 0;
        if(m==0) return 0;
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(matrix[i-1][j-1] == '0')
                    dp[i][j] = 0;
                else{
                    dp[i][j] = 1 + min(dp[i-1][j],min(dp[i][j-1], dp[i-1][j-1]));
                }
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};

int main(){
    // vector<vector<char> > matrix = {
    //     {'1','0','1','0','0'},
    //     {'1','0','1','1','1'},
    //     {'1','1','1','1','1'},
    //     {'1','0','0','1','0'}
    // };
    // Solution A;
    // cout << A.maximalSquare(matrix);
}