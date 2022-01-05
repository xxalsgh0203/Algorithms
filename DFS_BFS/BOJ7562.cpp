#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h> // memset
using namespace std;

int T, I;
int visited[300][300] = {0};
int graph[300][300] = {0};
int dx[8] = {-2,-1,1,2,-2,-1,1,2}; // 말이 이동할 수 있는 x좌표
int dy[8] = {1,2,2,1,-1,-2,-2,-1}; // 말이 이동할 수 있는 y좌표
queue<pair<int, int> > q;

void bfs(int a, int b, int c, int d){
    int distance;
    visited[a][b] = 1; // 시작점 방문처리
    q.push(make_pair(a,b)); // 시작점 큐에 삽입

    while(!q.empty()){ 
        int x = q.front().first;
        int y = q.front().second;

        if(x==c && y==d){ // 도착지점에 말이 도착하면
            distance = graph[x][y]; // distance 에 거리 기록
        }

        q.pop();

        for(int i=0; i<8; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            if(next_x>=0 && next_y>=0 && next_x<I && next_y<I){ // 말이 이동한 곳이 체스판을 벗어나지 않을때
                if(visited[next_x][next_y] != 1){
                    q.push(make_pair(next_x, next_y)); // 이동한 말의 좌표 queue 에 push
                    graph[next_x][next_y] = graph[x][y] + 1; // 그래프에 해당 좌표까지 말이 이동할 수있는 최단거리 갱신
                    visited[next_x][next_y] = 1; // 말이 이동한 곳의 좌표 방문처리
                }
            }
        }
    }

    printf("%d\n", distance); // 말이 이동한 최소횟수 출력
}


int main(){
    cin >> T;

    for(int i=0; i<T; i++){
        int a, b, c ,d;
        cin >> I; // 체스판의 한변의 길이 입력
        cin >> a >> b;
        cin >> c >> d;

        bfs(a,b,c,d);
        memset(graph,0,sizeof(graph)); // 다음 체스판 계산을 위해 그래프 초기화
        memset(visited,0,sizeof(visited)); // 다음 체스판 계산을 위해 visited 기록부 초기화
    }
    
    return 0;
}