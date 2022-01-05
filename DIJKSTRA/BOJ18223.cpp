#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E, P; // 정점의 개수 V, 간선의 개수 E, 건우 P
const int INF = 987654321;
vector <pair<int,int> > map[5001];

void Input(){
    cin >> V >> E >> P;
    for(int i=0; i<E; i++){
        int a, b, d;
        cin >> a >> b >> d;
        map[a].push_back(make_pair(b,d)); // node, dist
        map[b].push_back(make_pair(a,d));
    }
}

int dijkstra(int start, int end){
    vector <int> dist(V+1, INF);
    priority_queue <pair<int, int> > pq;
    pq.push(make_pair(0, start)); // distance , start
    dist[start] = 0;

    while(!pq.empty()){
        int curNode = pq.top().second;
        int curDist = -pq.top().first;

        pq.pop();
        
        if(dist[curNode] < curDist)
            continue;

        for(int i=0; i<map[curNode].size(); i++){
            int nextNode = map[curNode][i].first;
            int nextDist = map[curNode][i].second + curDist;

            if(dist[nextNode] > nextDist){
                dist[nextNode] = nextDist;
                pq.push(make_pair(-nextDist, nextNode));
            }
        }
    }

    return dist[end];
}

void Solve(){
    int minjoonToKunwoo = dijkstra(1, P);
    int KunwooToMasan = dijkstra(P, V);
    int minjoonToMasan = dijkstra(1, V);
    
    if(minjoonToKunwoo + KunwooToMasan == minjoonToMasan)
        cout << "SAVE HIM";
    else
        cout << "GOOD BYE";
}

int main(){
    Input();
    Solve();
}