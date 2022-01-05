#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> first;
vector <int> second;
vector <int> result;

int lowerBound(int start, int end, int target){
    
    while(start<end){
        int middle = (start + end) / 2;
        if(first[middle] >= target){
            end = middle;
        }
        else
            start = middle + 1;
    }

    return end;
}

int upperBound(int start, int end, int target){
    
    while(start<end){
        int middle = (start + end) / 2;
        if(first[middle] > target)
            end = middle;
        else
            start = middle + 1;
    }
    return end;
}

int main() {
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    int N, temp;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> temp;
        first.push_back(temp);
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        cin >> temp;
        second.push_back(temp);
    }

    sort(first.begin(), first.end());

    for(int i=0; i<M; i++){
        int upper = upperBound(0, N-1, second[i]);
        int lower = lowerBound(0, N-1, second[i]);
        if(upper == N-1 && second[i] == first[N-1]){ //Upper는 card 변수값보다 무조건 더 큰 값중 가장 작은애를 가리켜야하는데 card 변수보다 큰 값이 배열에 존재하지 않을 경우엔 배열에서 그냥 맨 마지막 애를 가리키고 있을테니 ++ 해준다
            upper++;
        }
        result.push_back(upper-lower);
    }

    for(int i=0; i<M; i++){
        cout << result[i] << " ";
    }
    
}