#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#define INF 987654321
using namespace std;
int TC;
int N, M, W;
int dist[501];
vector <pair<pair<int,int>, int> > city; 

void Init(){
    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }
    city.clear();
}

void Bellman_Ford(){
    dist[1] = 0;

    for(int i=0; i<N-1; i++){
        for(int j=0; j<city.size(); j++){
            int from = city[j].first.first;
            int to = city[j].first.second;
            int cost = city[j].second;

            if(dist[from] == INF)
                continue;

            if(dist[to] > dist[from] + cost)
                dist[to] = dist[from] + cost;
        }
    }

    for(int i=0; i<city.size(); i++){
        int from = city[i].first.first;
        int to = city[i].first.second;
        int cost = city[i].second;

        if(dist[to] > dist[from] + cost){
            cout << "YES" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
    return;
}

int main(){

    cin >> TC;

    for(int i=0; i<TC; i++){
        Init();
        cin >> N >> M >> W;

        for(int i=0; i<M; i++){
            int S, E, T;
            cin >> S >> E >> T;
            city.push_back(make_pair(make_pair(S,E), T));
            city.push_back(make_pair(make_pair(E,S), T));
        }

        for(int i=0; i<W; i++){
            int S, E, T;
                        cin >> S >> E >> T;
            city.push_back(make_pair(make_pair(S,E), -T));

        }

        Bellman_Ford();
    }

}