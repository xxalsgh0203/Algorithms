#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <climits>
using namespace std;
int N;
long long solution[5001];
long long INF = LLONG_MAX;

void Input(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> solution[i];
    }

    sort(solution, solution + N);
}

void Solve(){
    long long Result_L, Result_R, Result_F;

    for(int i=0; i<N; i++){
        int left = i+1, right = N-1, first = i;

        while(left < right){
            long long diff = solution[left] + solution[right] + solution[first];

            if(abs(diff) < INF){
                INF = abs(diff);
                Result_L = solution[left];
                Result_R = solution[right];
                Result_F = solution[first];
            }

            if(diff >= 0){
                right--;
            }
            else{
                left++;
            }
        }
    }

    cout << Result_F << " " << Result_L << " " << Result_R;
}

int main(){
    Input();
    Solve();
}