#include <iostream>
using namespace std;

int dpmap[12];

void dp(int num){
    dpmap[0] = 0;
    dpmap[1] = 1;
    dpmap[2] = 2;
    dpmap[3] = 4;

    for(int i=4; i<=num; i++){
        dpmap[i] = dpmap[i-1] + dpmap[i-2] + dpmap[i-3];
    }

    cout << dpmap[num] << endl;
}

int main(){
    int T, n;
    cin >> T; // 테스트 케이스 개수 입력
    for(int i=0; i<T; i++){
        cin >> n;
        dp(n); 
    }
}