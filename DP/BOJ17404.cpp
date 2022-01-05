#include <iostream>
#include <algorithm>
using namespace std;
int N;
const int INF = 987654321;
int house[1001][3];
int dp[1001][3];

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<3; j++){
            cin >> house[i][j];
        }
    }
}

void Solve(){
    int result = INF;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i==j)
                dp[0][j] = house[0][j];
            else
                dp[0][j] = INF;
        }

        for(int j=1; j<=N-1; j++){
            dp[j][0] = min(dp[j-1][1], dp[j-1][2]) + house[j][0];
            dp[j][1] = min(dp[j-1][0], dp[j-1][2]) + house[j][1];
            dp[j][2] = min(dp[j-1][0], dp[j-1][1]) + house[j][2];
        }

        for(int j=0; j<3; j++){
            if(i!=j)
                result = min(result, dp[N-1][j]);
        }
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}