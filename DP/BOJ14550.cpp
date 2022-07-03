#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int board[205];
int dp[205][205];  // DP[i][j] = i번째 턴일때 j에 도달할 수있는 최댓값

void init(){
    for(int i=0; i<205; i++){
        for(int j=0; j<205; j++){
            dp[i][j] = -INF;
        }
    }

    memset(board, 0, sizeof(board));
}

int main(){
    int N, S, T;

    while(true){
        cin >> N;
        if(N == 0)
            break;
 
        init();

        cin >> S >> T;

        for(int i=1; i<=N; i++){
            cin >> board[i];
        }

        dp[0][0] = 0; 

        for(int i=1; i<=N+1; i++){   // N : 출발점과 별 사이의 칸 수
            for(int j=1; j<=T; j++){
                for(int k=1; k<=S; k++){
                    if(i-k < 0)
                        continue;
                    dp[j][i] = max(dp[j][i], dp[j-1][i-k] + board[i]);
                }
            }
        }
        
        int answer = -INF;
        for(int i=1; i<=T; i++){
            answer = max(answer, dp[i][N+1]);
        }

        cout << answer << '\n';
    }

    return 0;
}