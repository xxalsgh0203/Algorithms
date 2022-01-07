#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321
int N, M;
int A, B, C;
long long dist[501];
vector<pair<pair<int,int> , int> > map;

void Input(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }

    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        map.push_back(make_pair(make_pair(A,B), C));
    }
}

void Bellman_Ford(){
    dist[1] = 0;
    for(int i=1; i<N; i++){
        for(int j=0; j<map.size(); j++){
            int from = map[j].first.first;
            int to = map[j].first.second;
            int cost = map[j].second;

            if(dist[from] == INF)   // 이미 한번 계산된 정점인지 확인
                continue;

            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    }

    for(int i=0; i<map.size(); i++){
        int from = map[i].first.first;
        int to = map[i].first.second;
        int cost = map[i].second;

        if(dist[from] == INF)
            continue;

        if(dist[to] > dist[from] + cost){
            cout << "-1" << '\n';
            return;
        }
    }

    for(int i=2; i<=N; i++){
        if(dist[i] == INF)
            cout << "-1" << '\n';
        else
            cout << dist[i] << '\n';
    }
}

void Solve(){
    Input();
    Bellman_Ford();
}

int main(){
    Solve();

    return 0;
}