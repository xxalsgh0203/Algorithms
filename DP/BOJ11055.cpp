#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];
int N; // 수열의 크기

void debugging(){
    for(int i=0; i<N; i++){
        cout << dp[i] << " ";
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
        dp[i] = A[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<i; j--){
            if(A[i]>A[j] && dp[i] < A[i] + dp[j]){
                dp[i] = A[i] + dp[j];
            }            
        }
    }

    int sum = 0;    
    for(int i=0; i<N; i++){
        sum = max(dp[i], sum);
    }

    // debugging();
    cout << sum;
}
