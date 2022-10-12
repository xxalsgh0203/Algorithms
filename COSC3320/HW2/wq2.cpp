#include <stdio.h>
#include <iostream>
#include <vector>

#define MAX 4 // 1부터 5까지 수의 순열을 구한다.

using namespace std;

vector<int> result;
int visit[MAX]; 

void print_permutation() { // 순열 출력
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}

void derangement(int count) { // count개의 수를 이용해 순열을 만든다.ㅑㄹㄹ랴
    if (count == 5) {
        print_permutation();
        return;
    }
    
    for (int i = 1; i <= MAX; i++) {
        if (visit[i] == true || i == count) // 이미 사용한 숫자라면 다음으로 넘긴다.
            continue;
        
        // (!) Back Tracking 사용
        visit[i] = true; // 방문했다는 표시를 남기고
        result.push_back(i); // result 벡터에 현재 값을 넣어준다.
        
        derangement(count + 1); // DFS를 사용하여 한 칸 더 내려간다.
        
        result.pop_back(); // Back Tracking
        visit[i] = false; // i에서 빠져나왔기때문에 visit[i]를 false로 바꿔준다.
    }
}

int main() {
    derangement(1);
    
    return 0;
}