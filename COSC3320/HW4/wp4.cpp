#include <iostream>
#include <queue>
using namespace std;

queue <pair<int, pair<int, int> > > q;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int map[5][5];
int dp[5][5];

bool InRange(int x, int y){
    if(x >= 0 && y >= 0 && x < 5 && y < 5)
        return true;
    else 
        return false;
}

void BFS(){
    q.push(make_pair(0, make_pair(0,0)));

    while(!q.empty()){
        int cnt = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();

        for(int i=0; i<4; i++){
            int nx = x + (map[x][y] * dx[i]);
            int ny = y + (map[x][y] * dy[i]);

            if(InRange(nx, ny)){
                if(dp[nx][ny] > cnt + 1){
                    dp[nx][ny] = cnt + 1;
                    q.push(make_pair(cnt + 1, make_pair(nx,ny)));
                }
            }
        }
    }
}

int main(){

    map[0][0] = 3;
    map[0][1] = 5;
    map[0][2] = 7;
    map[0][3] = 4;
    map[0][4] = 6;

    map[1][0] = 5;
    map[1][1] = 3;
    map[1][2] = 1;
    map[1][3] = 5;
    map[1][4] = 3;

    map[2][0] = 2;
    map[2][1] = 8;
    map[2][2] = 3;
    map[2][3] = 1;
    map[2][4] = 4;

    map[3][0] = 4;
    map[3][1] = 5;
    map[3][2] = 7;
    map[3][3] = 2;
    map[3][4] = 3;

    map[4][0] = 3;
    map[4][1] = 1;
    map[4][2] = 3;
    map[4][3] = 2;
    map[4][4] = 0;

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            dp[i][j] = 99;
        }
    }

    BFS();

    // for(int i=0; i<5; i++){
    //     for(int j=0; j<5; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[4][4];
    
}