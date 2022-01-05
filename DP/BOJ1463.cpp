#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h> // memset
#include <algorithm> // min
using namespace std;
#define MAX 1000001

vector <pair<int, int> > v;
int dptable[MAX] = {0};

void dp(int num){
    for(int i=2; i<=num; i++){
        dptable[i] = dptable[i-1] + 1;
        if(i%2 == 0){
            dptable[i] = min(dptable[i], dptable[i/2] + 1);
        }
        if(i%3==0){
            dptable[i] = min(dptable[i], dptable[i/3] + 1);
        }
    }

    cout << dptable[num];
}

int main(){
    int X;
    cin >> X;

    dp(X);

    return 0;
}