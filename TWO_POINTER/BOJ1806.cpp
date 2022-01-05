#include <iostream>
#include <algorithm>
#define INF 987654321
#define MAX 100001
using namespace std;

int N, S;
int order[MAX];

int main(){
    cin >> N >> S;
    for(int i=0; i<N; i++){
        cin >> order[i];
    }

    int left = 0, right = 0;
    int sum = order[0];
    int result = INF;

    // 투 포인터 알고리즘
    while(left <= right && right < N){
        if(sum < S){
            right++;
            sum += order[right];
        }
        else if(sum == S){
            result = min(result, right - left + 1);
            right++;
            sum += order[right];
        }
        else if(sum > S){
            result = min(result, right - left + 1);
            sum -= order[left];
            left++;
        }
    }

    if(result == INF)
        cout << 0;
    else
        cout << result;
}