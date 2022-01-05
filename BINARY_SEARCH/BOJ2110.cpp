#include <iostream>
#include <algorithm>
using namespace std;
int N, C; // N:집의개수 C:공유기의 개수
int house[200001];

void Input(){
    cin >> N >> C;
    for(int i=0; i<N; i++){
        cin >> house[i];
    }
    sort(house, house+N); // 정렬
}

int binary_search(){
    int left = 1; // 최소길이
    int right = house[N-1]; // 최대길이
    int answer;
    while(left <= right){
        int middle = (left + right) / 2;
        int recent_router_index = house[0]; // 첫 집에 설치
        int router_num = 1; // 공유기 설치 개수
        for(int i=0; i<N; i++){
            if(house[i] - recent_router_index >= middle){
                router_num++;
                recent_router_index = house[i];
            }
        }

        if(C > router_num){
            right = middle - 1;
        }
        else{ // 현재간격으로 설치한 공유기의 간격이 c 와 일치하여도 더 넓은 간격으로 설치해도 되기 때문에 계속 answer 을 검사한다
            left = middle + 1;
            answer = middle;
        }
    }

    return answer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    cout << binary_search();
}