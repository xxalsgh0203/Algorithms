#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
int N, M, X;
int start, destination, t;
vector <pair<int,int> > goinggraph[1001]; // 나가는 방향
vector <pair<int,int> > cominggraph[1001]; // 들어오는 방향
int goingdist[1001];
int comingdist[1001];

void Input(){
    cin >> N >> M >> X;
    for(int i=0; i<M; i++){
        cin >> start >> destination >> t;
        goinggraph[start].push_back(make_pair(destination, t)); // 그래프 초기화
        cominggraph[destination].push_back(make_pair(start, t));
    }
}

void caldist(vector <pair<int,int> > graph[1001], int* dist, int start){
    for(int i=1; i<=N; i++){
        dist[i] = INF;
    }
    priority_queue <pair<int,int> > pq; // cost, vertex
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while(!pq.empty()){
        int curCost = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if(dist[curNode] < curCost) // 이미 처리된 노드라면 무시
            continue;

        for(int i=0; i<graph[curNode].size(); i++){
            if(curCost + graph[curNode][i].second < dist[graph[curNode][i].first]){
                dist[graph[curNode][i].first] = curCost + graph[curNode][i].second;
                pq.push(make_pair(-dist[graph[curNode][i].first], graph[curNode][i].first));
            }
        }
        
    }
}

void Calculate(){
    caldist(goinggraph, goingdist, X);
    caldist(cominggraph, comingdist, X);
}

void getResult(){
    int sum = 0;
    int max = 0;

    for(int i=1; i<=N; i++){
        sum += goingdist[i];
        sum += comingdist[i];
        if(sum > max)
            max = sum;
        sum = 0;
    }
    cout << max;
}

// void debugging(){
//     for(int i=1; i<=N; i++){
//         cout << goingdist[i] << " ";
//     }

//     cout << '\n';

//     for(int i=1; i<=N; i++){
//         cout << comingdist[i] << " ";
//     }
// }

int main(){
    Input();    
    Calculate();
    // debugging();
    getResult();
}