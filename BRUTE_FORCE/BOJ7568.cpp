#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int weight, height, N;
    vector <pair<int, int> > v;
    queue <int> ranking;
    cin >> N; // 학생수 입력
    for(int i=0; i<N; i++){
        cin >> weight >> height; // 키 몸무게 입력
        v.push_back(make_pair(weight, height)); 
    }

    for(int i=0; i<N; i++){
        int cnt = 1;
        for(int j=0; j<N; j++){
            if(v[i].first < v[j].first && v[i].second < v[j].second)
                cnt++;
        }
        ranking.push(cnt);
    }

    while(!ranking.empty()){
        int result = ranking.front();
        ranking.pop();
        cout << result << " ";
    }

    return 0;
}