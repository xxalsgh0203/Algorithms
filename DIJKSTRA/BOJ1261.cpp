#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int INF = 987654321;
int graph[101][101];
int cost[101][101];
bool visited[101][101] = {false};
int N, M;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++) { // 입력예시가 띄어쓰기 없는 입력이므로 char 로 입력을받아 int 로 바꿔줘야한다
        string S; cin >> S;
        for (int j = 0; j < N; j++){
            graph[i][j] = S[j] - '0';
            cost[i][j] = INF;
        }
    }
}

bool inRange(int nx, int ny){
    return nx>=0 && nx<M && ny>=0 && ny<N;
}

int bfs(int x, int y){
    priority_queue <pair<int, pair<int, int> > > pq;
    pq.push(make_pair(0, make_pair(0,0)));
    cost[0][0] = 0;
    
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if(x==M-1 && y==N-1){
            return cost[M-1][N-1];
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(inRange(nx, ny)){
                if(graph[nx][ny] == 1 && !visited[nx][ny]){ // 벽이 있을때
                    cost[nx][ny] = cost[x][y] + 1;
                    visited[nx][ny] = true;
                    pq.push(make_pair(-cost[nx][ny],make_pair(nx,ny)));
                }
                else if(graph[nx][ny] == 0 && !visited[nx][ny]){ // 벽이 없을때
                    cost[nx][ny] = cost[x][y];
                    visited[nx][ny] = true;
                    pq.push(make_pair(-cost[nx][ny],make_pair(nx,ny)));
                }
            }
        }
    }
}

void debugging(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cout << cost[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    cout << bfs(0,0);
}