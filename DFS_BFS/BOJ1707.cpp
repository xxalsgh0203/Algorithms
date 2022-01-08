#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 20001
#define RED 1 
#define BLUE 2
using namespace std;

int TC;
int K;
int V, E;
int visited[MAX];
vector<int> graph[MAX];

void Init(){
    for(int i=0; i<=V; i++){
        graph[i].clear();
    }
    memset(visited, false, sizeof(visited));
}

void bfs(int start){
    queue<int> q;
    int color = RED;
    
    visited[start] = color;
    q.push(start);

    while(!q.empty()){
        int current = q.front();
        q.pop();

        if(visited[current] == RED)
            color = BLUE;
        else if(visited[current] == BLUE)
            color = RED;

        for(int i=0; i<graph[current].size(); i++){
            int next = graph[current][i];
            if(!visited[next]){
                visited[next] = color;
                q.push(next);
            }
        }
    }
}

bool isBipartiteGraph(){
    for(int i=1; i<=V; i++){
        for(int j=0; j<graph[i].size(); j++){
            int next = graph[i][j];
            if(visited[i] == visited[next])
                return false;
        }
    }

    return true;
}

int main(){
    cin >> TC;
    for(int t=0; t<TC; t++){ // 테스트 케이스만큼
        cin >> V >> E;
        for(int i=0; i<E; i++){
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }

        for(int i=1; i<=V; i++){
            if(!visited[i]){
                bfs(i);
            }
        }

        if(isBipartiteGraph()){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }

        Init();
    }

    return 0;
}