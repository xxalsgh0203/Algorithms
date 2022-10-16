// Submission ID : b8e00ce2-2068-4773-8b4a-2955ae5b461a

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int m, n;
int matrix[11][101];
int dp[11][101];

void reset(){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 1e9;
        }
    }

    for(int i=0; i<m; i++){
        dp[i][0] = matrix[i][0];
    }
}

bool inRange(int x, int y){
    if(x>=0 && y>=0 && x<m && y<n)
        return true;
    else 
        return false;
}

void Solve(int x, int y){
    if(y==n-1)
        return;

    for(int i=-1; i<2; i++){
        int next_x = x + i;
        next_x = next_x + m;
        next_x = next_x % m;
        int next_y = y + 1;
        if(inRange(next_x, next_y)){
            dp[next_x][next_y] = min(dp[next_x][next_y],dp[x][y] + matrix[next_x][next_y]);
            Solve(next_x, next_y);
        }
    }
}

int main(){

    vector <int> result;

    cin >> m >> n;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }

    for(int i=0; i<m; i++){
        reset();
        Solve(i,0);

        int temp_result = 1e9;
        for(int j=0; j<m; j++){
            if(dp[j][n-1] < temp_result){
                temp_result = dp[j][n-1];
            }
        }
        result.push_back(temp_result);
    }
    
    int min_num = 1e9;
    for(int i=0; i<result.size(); i++){
        if(min_num > result[i])
            min_num = result[i];
    }

    cout << min_num;

}