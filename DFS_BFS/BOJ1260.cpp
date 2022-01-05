#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
queue<int> q;
int graph[1001][1001];
int visited[1001] = {0};
int N, M; 

void dfs(int x){
    cout << x << " ";
    visited[x] = 1;
    for(int i=1; i<=N; i++){
        if(graph[x][i]==1 && visited[i]==0){
            if(x==i)
                continue;
            dfs(i);
        }
    }
}

void bfs(int x){
    visited[x] = 1;
    q.push(x);
    while(!q.empty()){
        int first = q.front();
        cout << first << " ";
        for(int i=1; i<=N; i++){
            if(graph[first][i]==1 && visited[i]==0){
                if(first==i)
                    continue;
                q.push(i);
                visited[i] = 1;
            }
        }
        q.pop();
    }
}

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);
    int start;
    cin >> N >> M >> start;
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    dfs(start);
    cout << '\n';
    memset(visited, 0 ,sizeof(visited));
    bfs(start);

    return 0;
}