#include <iostream>
#include <algorithm>
using namespace std;

int dpmap[101][100001];
int weight[101];
int value[101];
int N, K;

void Input(){
cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin >> weight[i];
        cin >> value[i];
    }
}

void dp(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            if(j-weight[i]>=0){
                dpmap[i][j] = max(dpmap[i-1][j], dpmap[i-1][j-weight[i]] + value[i]);
            }
            else
                dpmap[i][j] = max(dpmap[i][j], dpmap[i-1][j]);
        }
    }
}

int main(){
    Input();

    dp();

    cout << dpmap[N][K];
}