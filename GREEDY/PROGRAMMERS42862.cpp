#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector <int> temp(n+1, 0);

    for(int i=0; i<reserve.size(); i++){
        temp[reserve[i]] = 2;
    }
    for(int i=0; i<lost.size(); i++){
        temp[lost[i]]--;;
    }

    for(int i=1; i<=n; i++){
        if(temp[i] == 2 && temp[i-1] == -1){
            temp[i]--;
            temp[i-1]++;
        }
        if(temp[i] == 2 && temp[i+1] == -1){
            temp[i]--;
            temp[i+1]++;
        }
    }

    // for(int i=1; i<=n; i++){
    //     cout << temp[i] << " ";
    // }
    // cout << '\n';

    for(int i=1; i<=n; i++){
        if(temp[i] != -1){
            answer++;
        }
    }

    return answer;
}

// 0 2 0 -1

int main(){
    int n = 5;
    vector <int> lost;
    lost.push_back(2);
    lost.push_back(4);
    vector <int> reserve;
    // reserve.push_back(1);
    reserve.push_back(3);
    // reserve.push_back(5);
    cout << solution(n, lost, reserve);
}

