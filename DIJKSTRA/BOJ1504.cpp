#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, E, v1, v2;
const int INF = 987654321;
vector<pair<int,int> >graph[801];

void Input(){
    cin >> N >> E;
    for(int i=0; i<E; i++){
        int source, destination, dist;
        cin >> source >> destination >> dist;
        graph[source].push_back(make_pair(destination, dist));
        graph[destination].push_back(make_pair(source, dist));
    }
    cin >> v1 >> v2;
}

vector<int> dijkstra(int start){
    vector <int> dist(N+1, INF);
    dist[start] = 0; // 시작점
    priority_queue <pair<int, int> >  pq;
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        for(int i=0; i<graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int totalDist = graph[curNode][i].second + curDist;
            if(dist[nextNode] > totalDist){
                dist[nextNode] = totalDist;
                pq.push(make_pair(-totalDist, nextNode));
            }
        }
    }
    return dist;
}

void Solve(){
    vector<int> result1 = dijkstra(1);
    vector<int> result2 = dijkstra(v1);
    vector<int> result3 = dijkstra(v2);
    
    int result = min(result1[v1] + result2[v2] + result3[N], result1[v2] + result3[v1] + result2[N]);

    if(result>=INF || result<0)
        cout << "-1";
    else
        cout << result;
}


int main(){
    Input();
    Solve();
}