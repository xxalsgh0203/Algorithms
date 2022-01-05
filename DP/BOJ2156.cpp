#include <stdio.h>

int getMinValue(int num1, int num2){
    if(num1 < num2)
        return num1;
    else
        return num2;
}

int main(){
    int N;
    scanf("%d", &N); // N개의 집

    int dp[1001][3]; // 색깔을 칠하는데 드는 최소 비용
    int rgb[1001][3]; // 집마다 R, G, B 를 칠하는데 드는 비용 
   
    for(int i=1; i<N+1; i++){
        for(int j=0; j<3; j++)
            scanf("%d", &rgb[i][j]);
    }

    //  첫번째 집까지 색깔별로 칠하는데 드는 최소 비용 = 첫번째 집의 각각 색깔별 비용
    dp[1][0] = rgb[1][0]; 
    dp[1][1] = rgb[1][1];
    dp[1][2] = rgb[1][2];

    // i번째 집까지 칠하는데 드는 최소 비용. i-1 과 색깔중복 피하도록. 보텀업 다이나믹 프로그래밍
    for(int i=2; i<N+1; i++){
        dp[i][0] = getMinValue(dp[i-1][1], dp[i-1][2]) + rgb[i][0]; //i번째 집에 0번색깔을 칠하려면 i-1번집 색깔이 1 또는 2여야함
        dp[i][1] = getMinValue(dp[i-1][0], dp[i-1][2]) + rgb[i][1]; //i번째 집에 1번색깔을 칠하려면 i-1번집 색깔이 0 또는 2여야함
        dp[i][2] = getMinValue(dp[i-1][0], dp[i-1][1]) + rgb[i][2]; //i번째 집에 2번색깔을 칠하려면 i-1번집 색깔이 0 또는 1여야함
    }

    int min = dp[N][0];
    for(int i=0; i<3; i++){
        if(dp[N][i] < min)
            min = dp[N][i];
    }

    printf("%d", min);

}