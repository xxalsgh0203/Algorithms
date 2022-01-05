#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int graph[501][501];
int dp[501][501] = {0};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

bool InRange(int y, int x){
    if(y>=0 && y<N && x>=0 && x<M)
        return true;
    else 
        return false;
}

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> graph[i][j];
        }
    }
}

int DFS(int y, int x){
    if(y==N-1 && x==M-1)
        return 1;
    else if(dp[y][x] == -1){
        dp[y][x] = 0;
        for(int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            
        if(graph[ny][nx] < graph[y][x] && InRange(ny,nx)){
            dp[y][x] += DFS(ny, nx);
            }
        }
    }
    return dp[y][x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    
    memset(dp, -1, sizeof(dp));
    cout << DFS(0,0);
}