#include <iostream>
#include <algorithm>
using namespace std;
int N, result;
int nums[102];
long dp[102][21];

void Input(){
    cin >> N;
    for(int i=1; i<=N-1; i++){
        int temp;
        cin >> nums[i];
    }
    cin >> result;
}

void Solve(){
    dp[1][nums[1]] = 1;
    for(int i=2; i<=N-1; i++){
        int prev = nums[i];
        for(int j=0; j<21; j++){
            if(dp[i-1][j]){
                if(j+ prev <= 20){
                    dp[i][j+prev] += dp[i-1][j];
                }
                if(j - prev >= 0){
                    dp[i][j-prev] += dp[i-1][j];
                }
            }
        }
    }

    cout << dp[N-1][result];
}

int main(){
    Input();
    Solve();
}
