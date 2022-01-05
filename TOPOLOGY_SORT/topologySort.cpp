// 1. 진입 차수가 0 인 정점을 큐에 삽입한다.
// 2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거합니다.
// 3. 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입합니다.
// 4. 큐가 빌 때까지 2번~3번 과정을 반복합니다. 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재하는 것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과입니다.

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector <int> a[MAX];

void topologySort(){
    int result[MAX];
    queue <int> q;
    // 진입차수가 0 인 노드를 큐에 삽입합니다
    for(int i=1; i<=n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문해야함
    for(int i=1; i<=n; i++){
        // n개를 방문하기 전에 큐가 빈다면 사이클이 발생한것
        if(q.empty()){
            cout << "싸이클이 발생하였습니다!";
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }

    for(int i=1; i<=n; i++){
        cout << result[i] << " ";
    }

}

int main(){
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;

    topologySort();
}