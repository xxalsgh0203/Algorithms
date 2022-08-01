#include <iostream>
using namespace std;

int main(){
    int M, N;
    int high = 0;
    int snack[1000001];

    cin >> M >> N;
    for(int i=0; i<N; i++){
        cin >> snack[i];
        high = max(snack[i], high);
    }

    int left = 1;
    int right = high;

    int answer = 0;

    while(left <= right){
        int count = 0;
        int middle = (left + right) / 2;

        for(int i=0; i<N; i++){
            count += snack[i] / middle;
        }

        if(count >= M){ // 과자를 나누어 줄 수 있을 때
            left = middle + 1;
            answer = middle;
        }
        else{
            right = middle - 1;
        }
    }

    cout << answer;
}