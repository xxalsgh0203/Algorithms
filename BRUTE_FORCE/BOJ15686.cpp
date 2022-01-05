#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;
int N, M;
int city[51][51];
bool selected[13];
const int INF = 987654321;
int result = INF;
vector <pair<int,int> > chicken, house, V;

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> city[i][j];
            if(city[i][j] == 2)
                chicken.push_back(make_pair(i,j));
            else if(city[i][j] == 1)
                house.push_back(make_pair(i,j));
        }
    }
}

int calDist(){
    int sum = 0;
    for(int i=0; i<house.size(); i++){
        int hx = house[i].first;
        int hy = house[i].second;
        int mindist = INF;

        for(int j=0; j<V.size(); j++){
            int cx = V[j].first;
            int cy = V[j].second;
            int d = abs(hx - cx) + abs(hy - cy);
            mindist = min(mindist, d);
        }

        sum += mindist;
    }

    return sum;
}

void Select(int idx, int cnt){ 
    if(cnt == M){
        result = min(result, calDist()); // 조합한 치킨집들로 계산
        return;
    }

    for(int i=idx; i<chicken.size(); i++){ // 조합
        if(selected[i])
            continue;
        selected[i] = true;
        V.push_back(chicken[i]);
        Select(i, cnt+1);
        selected[i] = false;
        V.pop_back();
    }
}

void Solve(){
    Select(0,0);
    cout << result;
}

int main(){
    Input();
    Solve();
}


