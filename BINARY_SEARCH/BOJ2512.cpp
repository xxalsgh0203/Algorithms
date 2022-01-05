#include <iostream>
#include <algorithm>
using namespace std;
int budget[10000];
int N, M, maxnum=0;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> budget[i];
        maxnum = max(maxnum, budget[i]);
    }
    cin >> M;
}

void Solve(){
    int left = 0; 
    int right = maxnum;
    long long result;
    while(left <= right){
        int middle = (left + right) / 2;
        long long sum = 0;
        for(int i=0; i<N; i++)
            sum += min(budget[i], middle);

        if(sum <= M){
            result = middle;
            left = middle+1;
        }
        else
            right = middle-1;
        
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}