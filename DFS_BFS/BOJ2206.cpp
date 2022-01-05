#include <iostream>
#include <queue>

using namespace std;
const int INF = 987654321;
int N, M;
int graph[1001][1001];
int dist[1001][1001][2];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void debugg(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << dist[i][j][0] << " ";
        }
        cout << '\n';
    }

    cout << '\n';
    cout << '\n';

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout << dist[i][j][1] << " ";
        }
        cout << '\n';
    }
}

bool inRange(int x, int y){
    if(x>=0 && x<N && y>=0 && y<M)
        return true;
    else
        return false;
}

void Input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) // 입력예시가 띄어쓰기 없는 입력이므로 char 로 입력을받아 int 로 바꿔줘야한다
    {
        string S; cin >> S;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = S[j] - '0';
        }
    }
}

int dijkstra(){
    queue <pair<pair<int, int>,int > > pq; // x,y,벽부순횟수
    pq.push(make_pair(make_pair(0,0),0));
    dist[0][0][0] = 1;

    while(!pq.empty()){
        int x = pq.front().first.first;
        int y = pq.front().first.second;
        int broke = pq.front().second;
        pq.pop();
        if(x==N-1 && y==M-1){
            return dist[N-1][M-1][broke];
        }
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(inRange(nx,ny)){ 
                //벽을 만났는데 벽을 뿌신적이없다면
                if (graph[nx][ny] == 1 && broke==0)
                {
                    dist[nx][ny][broke + 1] = dist[x][y][broke] + 1;
                    pq.push(make_pair(make_pair(nx,ny),broke+1));
                }
                    //벽이없고 방문하지않은곳이면 
                else if(graph[nx][ny]==0 && dist[nx][ny][broke]==0)
                {
                    dist[nx][ny][broke] = dist[x][y][broke] + 1;
                    pq.push(make_pair(make_pair(nx,ny),broke));
                }
            }
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    cout << dijkstra();
    // debugg();


}