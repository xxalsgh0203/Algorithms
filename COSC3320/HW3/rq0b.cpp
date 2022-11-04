#include <iostream>
#include <algorithm>
using namespace std;

int dp[100][100];

int main(){
    int n = 10;
    int arr[5] = {1,2,3,4,2};

    int answer = 0;

    for (int i=1; i<5; i++){
        int temp_answer = 0;
        for(int j=1; j<=i; j++){
            if(j % 2 == 0){
                if(arr[j-1] > arr[j]){
                    temp_answer++;
                    answer = max(temp_answer, answer);
                }
            }
            else{
                if(arr[j-1] < arr[j]){
                    temp_answer++;
                    answer = max(temp_answer, answer);
                }
            }
        }
    }

    cout << answer;
}