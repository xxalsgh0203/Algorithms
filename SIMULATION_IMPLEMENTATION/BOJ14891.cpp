#include <iostream>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;

vector<deque<int> > gear(5);
int rotCheck[5];

void Check(int target, int direction){ // 타켓 톱니바퀴의 움직임 방향에 따른 나머지 3개 톱니들의 움직임 기록
    rotCheck[target] = direction;

    // 왼쪽부터 체크
    for(int left = target - 1; left >= 1; left--){
        int right = left + 1;
        if(gear[left][2] != gear[right][6]){
            rotCheck[left] = rotCheck[right] * -1;
        }
        else
            break;
    }
    for(int right = target + 1; right <= 4; right++){
        int left = right - 1;
        if(gear[right][6] != gear[left][2]){
            rotCheck[right] = rotCheck[left] * -1;
        }
        else
            break;
    }
}

void Rotate(){ // 톱니 회전!!!
    for(int i=1; i<=4; i++){
        if(rotCheck[i] == 1){
            int temp = gear[i].back();
            gear[i].pop_back();
            gear[i].push_front(temp);
        }
        if(rotCheck[i] == -1){
            int temp = gear[i].front();
            gear[i].pop_front();
            gear[i].push_back(temp);
        }
    }
}

void getScore(){
    int score = 0;
    if(gear[1][0] == 1)
        score += 1;
    if(gear[2][0] == 1)
        score += 2;
    if(gear[3][0] == 1)
        score += 4;
    if(gear[4][0] == 1)
        score += 8;

    cout << score;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string info;
    int times;
    for(int i=1; i<=4; i++){
        cin >> info;
        for(int j=0; j<8; j++){
            int infos = info[j] - '0';
            gear[i].push_back(infos);
        }
    }
    cin >> times; // 몇번 회전 시킬건지
    for(int i=0; i<times; i++){
        int target, direction;
        cin >> target >> direction;
        Check(target, direction);
        Rotate();
        memset(rotCheck, 0, sizeof(rotCheck));
    }

    getScore();
}