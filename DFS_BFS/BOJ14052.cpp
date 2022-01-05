#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[8][8];
int c_map[8][8];
int N, M, empty_space;
int max_area = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

// 연구소 정보를 입력받음
void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}

void copyMap(int (*a)[8], int (*b)[8]){ // 더블포인터로 가능?
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            a[i][j] = b[i][j];
        }
    }
}

void Spread(){
    queue <pair<int, int> > q;
    int spreadMap[8][8];
    copyMap(spreadMap, c_map);

    for(int i=0; i<N; i++){ // 바이러스 퍼뜨리기
        for(int j=0; j<M; j++){
            if(c_map[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(spreadMap[nx][ny] == 0){
                    spreadMap[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    int count = 0; // 감염되지 않은 영역 크기 계산
    for(int i=0; i<N; i++){ 
        for(int j=0; j<M; j++){
            if(spreadMap[i][j] == 0){
                count++;
            }
        }
    }
    max_area = max(max_area, count);
}

void makeWall(int cnt){ // 모든 곳에 벽을 세워본다
    bool check[8][8];
    if(cnt==3){ // 벽을 3개 세웠다면 
        Spread(); // 바이러스 번식시킴
        return;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(c_map[i][j] == 0){
                c_map[i][j] = 1;
                makeWall(cnt+1);
                c_map[i][j] = 0;
            }
        }
    }
}

void Solve(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 0){
                copyMap(c_map, map);
                c_map[i][j] = 1;
                makeWall(1);
            }
        }
    }
    cout << max_area;
}

int main(){
    Input();
    Solve();
}