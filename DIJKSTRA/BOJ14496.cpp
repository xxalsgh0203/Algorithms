#include <iostream>
#include <queue>
using namespace std;
const int INF = 1000000000;
int dist[1001];
int a, b, N, M;
vector<pair<int,int> > graph[1001];

void Init(){
    for(int i=1; i<=N; i++)
        dist[i] = INF;
}

void Input(){
    cin >> a >> b; // word a, word b
    cin >> N >> M;
    Init();
    for(int i=0; i<M; i++){
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1].push_back(make_pair(node2, 1));
        graph[node2].push_back(make_pair(node1, 1));
    }
}

void Solve(){
    priority_queue <pair<int,int> > q;
    q.push(make_pair(0, a)); // 현재치환횟수,시작문자
    dist[a] = 0; // 틀렸습니다의 원인
    while(!q.empty()){
        int curTimes = q.top().first;
        int curWord = q.top().second;
        q.pop();

        if(curTimes > dist[curWord])
            continue;

        for(int i=0; i<graph[curWord].size(); i++){
            int next = graph[curWord][i].first;
            int totalTimes = curTimes + 1;
            if(dist[next] > totalTimes){
                dist[next] = totalTimes;
                q.push(make_pair(totalTimes, next));
            }
        }
    }

    if(dist[b] != INF)
        cout << dist[b];
    else
        cout << "-1";

    // for(int i=0; i<=N; i++){
    //     cout << dist[i] << " ";
    // }
}

int main(){
    Input();
    Solve();

    return 0;
}
