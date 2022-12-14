#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int numofNodes, numofEdges;

vector<int> FindMaxPath(int start, vector<pair<int,int> > graph[]){
    vector <int> dist(numofNodes, 0);
    priority_queue <pair<int, int> >  pq;
    
    pq.push(make_pair(0, start));

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = pq.top().first;
        pq.pop();

        for(int i=0; i<graph[curNode].size(); i++){
            int nextNode = graph[curNode][i].first;
            int totalDist = graph[curNode][i].second + curDist;
            if(dist[nextNode] < totalDist){
                dist[nextNode] = totalDist;
                pq.push(make_pair(totalDist, nextNode));
            }
        }
    }

    return dist;
}

int main(){
    
    int start, dest;

    cin >> numofNodes >> numofEdges;
    cin >> start >> dest;

    vector<pair<int,int> > graph[numofNodes];

    for(int i=0; i<numofEdges; i++){    
        int startNode, destNode, distance;

        cin >> startNode >> destNode >> distance;
        graph[startNode].push_back(make_pair(destNode, distance));
    }

    vector<int> result;

    result = FindMaxPath(start, graph);

    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }

    cout << result[dest];

    return 0;
}