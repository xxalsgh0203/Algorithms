#include <iostream>
#include <stdlib.h>
using namespace std;
int N;
long long int solution[100000];
long long int INF = 2000000000;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> solution[i];
    }
}

void Solve(){
    int left = 0, right = N-1;
    long long int Result_L, Result_R;

    while(left < right){
        int diff = solution[left] + solution[right];
        if(diff == 0){
            cout << solution[left] << " " << solution[right];
            return;
        }
        if(abs(diff) < INF){
            INF = abs(diff);
            Result_L = solution[left];
            Result_R = solution[right];
        }
        if(diff > 0){
            right--;
        }
        else if(diff < 0){
            left++;
        }
    }

    cout << Result_L << " " << Result_R;
}

int main(){
    Input();
    Solve();
}