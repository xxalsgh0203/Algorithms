#include <iostream>
#include <algorithm>

using namespace std;

int N;

long long getCnt(int X){ // X 보다 작은 수들의 갯수
    long long sum = 0;
    for(int i=1; i<=N; i++){
        sum += min(N, X/i);
    }
    return sum;
}

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    
    cin >> N;
    int K;
    cin >> K;

    int left = 1;
    int right = K;
    int result;

    while(left <= right){
        int middle = (left + right) / 2;
        long long target = getCnt(middle);
        if(target < K){
            left = middle + 1;
        }
        else
        {
            result = middle;
            right = middle - 1;
        }
    }

    cout << result;
    return 0;
}