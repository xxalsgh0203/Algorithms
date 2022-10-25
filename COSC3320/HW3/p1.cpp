#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    
    int result = 0;
    int n;
    cin >> n;
    int dp[2][10003];
    int arr[10003];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    for(int i=0; i<2; i++){
        for(int j=0; j<n; j++){
            dp[i][j] = 1;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j] && dp[0][j] + 1 > dp[0][i]){
                dp[0][i] = dp[0][j] + 1;
            }
        }
    }

    for(int i=n-2; i>=0; i--){
        for(int j=n-1; j>i; j--){
            if(arr[i] > arr[j] && dp[1][j] + 1 > dp[1][i])
                dp[1][i] = dp[1][j] + 1;
        }
    }

    for(int i=0; i<n; i++){
        int temp = dp[0][i] + dp[1][i] - 1;
        if(result < temp)
            result = temp;
    }

    cout << result;

}
