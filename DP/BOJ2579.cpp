#include <iostream>
#include <algorithm> // max
using namespace std;

int n; // n: 계단의 개수
int stairs[301];
int dpmap[10001];

void dp(){
    dpmap[1] = stairs[1];
    dpmap[2] = dpmap[1] + stairs[2];
    for(int i=3; i<=n; i++){
        dpmap[i] = max(dpmap[i-3]+stairs[i-1]+stairs[i] , dpmap[i-2]+stairs[i]);
    }

    cout << dpmap[n];
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> stairs[i];
    }

    dp();
}