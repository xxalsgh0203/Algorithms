#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;
vector <pair <int, int> > graph[1001];
int N, M; // 도시의 개수 N, 버스의 개수 M
int start, goal; // 시작도시, 끝도시

void Input(){
    cin >> N >> M;  
    for(int i=0; i<M; i++){
        int source, destination, cost;
        cin >> source >> destination >> cost;
        graph[source].push_back(make_pair(destination, cost));
    }
    
    cin >> start >> goal;
}

void dijkstra(){
    vector <int> distance(N+1, INF);
    priority_queue <pair<int, int> > pq; // 다음향할 도시까지의 거리, 다음향할 도시
    pq.push(make_pair(0, start)); // start 에서 출발
    distance[start] = 0;

    while(!pq.empty()){
        int curCost = -pq.top().first;
        int curVertex = pq.top().second;

        pq.pop();

        if(distance[curVertex] < curCost)
            continue;

        for(int i=0; i<graph[curVertex].size(); i++){
            int neighbor = graph[curVertex][i].first;
            int neighborDistance = graph[curVertex][i].second + curCost;

            if(neighborDistance < distance[neighbor]){
                distance[neighbor] = neighborDistance;
                pq.push(make_pair(-neighborDistance, neighbor));
            }
        }
    }
    
    cout << distance[goal];
}

int main(){
    Input();
    dijkstra();
}