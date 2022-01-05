#include <iostream>
using namespace std;

int dpmap[101][10] = {0};
int N;

void dp(){
    for(int i=1; i<10; i++){ // 사이즈 1일떄 dpmap 초기화
        dpmap[1][i] = 1; // 사이즈 1이고, 마지막 자리수가 i
    }

    for(int i=2; i<=N; i++){
        dpmap[i][0] = dpmap[i-1][1]; // 0 으로 끝나는 수 앞에는 1밖에 올 수 없음
        dpmap[i][9] = dpmap[i-1][8]; // 9 로 끝나는 수 앞에는 8밖에 올 수 없음
        for(int j=1; j<9; j++){
            dpmap[i][j] = (dpmap[i-1][j-1] + dpmap[i-1][j+1]) % 1000000000;
        }
    }
}


int main(){
    cin >> N;
    int sum = 0;

    dp();

    for(int i=0; i<=9; i++){
        sum += dpmap[N][i];
        sum %= 1000000000;
    }

    cout << sum;
}