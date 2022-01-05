#include <iostream>
using namespace std;
int n, box[1001], dp[1001];

void Input() {
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> box[i];
    }
}

void Solve() {
    for(int i=1; i<=n; i++){
        int max = 0;
        for(int j=0; j<i; j++){
            if(box[i] > box[j] && dp[j] > max){ // i 이전의 수 중에서 i보다 작은 수 중 가장 큰 dp값
                max = dp[j];
            }
        }

        dp[i] = max + 1;
    }

    int calmaxnum = 0;
    for(int i=0; i<=n; i++){    // dp[n] 이 무조건 가장 큰 값이 아니고, dp 배열내에서 가장 큰 값이 정답이다
        if(dp[i] > calmaxnum)
            calmaxnum = dp[i]; 
    }

    cout << calmaxnum;
}

int main() {
    Input();
    Solve();
}