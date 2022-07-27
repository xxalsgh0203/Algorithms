#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;
int cnt = 0;
int max_area = 0;
int temp_max_area = 0;
int map[503][503];
bool visited[503][503];
queue <pair<int, int> > q;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

bool inRange(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m)
        return true;

    return false;
}

void BFS(int x, int y){
    temp_max_area++;
    visited[x][y] = true;
    q.push(make_pair(x, y));
    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int vx = tx + dx[i];
            int vy = ty + dy[i];
            if(inRange(vx, vy) && !visited[vx][vy] && map[vx][vy] == 1){
                visited[vx][vy] = true;
                q.push(make_pair(vx, vy));
                temp_max_area++;
            }
        }
    }
}

int main(){
    
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && !visited[i][j]){
                cnt++;
                BFS(i, j);
            }
            max_area = max(max_area, temp_max_area);
            temp_max_area = 0;
        }
    }

    cout << cnt << '\n';
    cout << max_area;
}