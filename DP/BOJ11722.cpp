#include <iostream>
#include <algorithm>
using namespace std;
int N;
int A[1001];
int dp[1001];

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

void Init(){
    for(int i=0; i<N; i++){
        dp[i] = 1;
    }
}

void Solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            if(A[i] < A[j] && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maxlength = 0;
    for(int i=0; i<N; i++){
        maxlength = max(dp[i], maxlength);
    }

    cout << maxlength;
}

int main(){
    Input();
    Init();
    Solve();
}