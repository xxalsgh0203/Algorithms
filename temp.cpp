#include <iostream>
#include <utility>
#include <queue>
using namespace std;
 
#define X first
#define Y second
 
char board[1000][1000];
int F_dist[1000][1000];
int J_dist[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int r, c;
 
void F_bfs() {
    queue<pair<int, int> > Q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'F') {
                Q.push({ i, j });
                F_dist[i][j] = 1;
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx>=r || ny >= c) continue;
            if (board[nx][ny] == '#' || F_dist[nx][ny])continue;
            Q.push({ nx,ny });
            F_dist[nx][ny] = F_dist[cur.X][cur.Y] + 1;
        }
    }
}
 
int J_bfs() {
    F_bfs();

    // for(int i=0; i<r; i++){
    //     for(int j=0; j<c; j++){
    //         cout << F_dist[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    queue<pair<int, int> > Q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[i][j] == 'J') {
                Q.push({ i, j });
                J_dist[i][j] = 1;
            }
        }
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= r || ny >= c) {//범위를 넘어가면 탈출 성공
                return J_dist[cur.X][cur.Y]; 
            }
            if (board[nx][ny] == '#' || J_dist[nx][ny])continue;
            if (J_dist[cur.X][cur.Y] + 1 >= F_dist[nx][ny] && F_dist[nx][ny]) continue; //불이 더 빨리 도착하면 무시
            Q.push({ nx,ny });
            J_dist[nx][ny] = J_dist[cur.X][cur.Y] + 1;
        }
    }


    return -1;
}
 
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    int res = J_bfs();

    if (res != -1) cout << res;
    else cout << "IMPOSSIBLE";
 
 
    return 0;
}