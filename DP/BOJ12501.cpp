#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 15;
int Time[MAX];
int Profit[MAX];
int DP[MAX];
int N;

void Input(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> Time[i];
        cin >> Profit[i];
    }
}

void Solution(){
    for(int i=N; i>=1; i--){
        if(i + Time[i] >= N + 2)
            DP[i] = DP[i+1];
        else
            DP[i] = max(DP[i+1], DP[i+Time[i]] + Profit[i]);
    }

    cout << DP[1];
}

int main(){
    Input();

    Solution();
}