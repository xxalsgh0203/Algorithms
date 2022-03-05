#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
int N, W, H;
int dx[5] = {0,-1,0,1,0};
int dy[5] = {0,0,1,0,-1};
int order[21];
int map[21][21];
bool visited[21][21];
int init_x, init_y;
bool inRange(int x, int y){
    if(x<0 || y<0 || x>=H || y>=W)
        return false;
    else 
        return true;
}
void Move(int direction){
    int nRx = init_x + dx[direction];
    int nRy = init_y + dy[direction];
    while(1){
        nRx = init_x + dx[direction];
        nRy = init_y + dy[direction];
        if(map[nRx][nRy] == 1 || !inRange(nRx, nRy)){
            return;
        }
        init_x = nRx;
        init_y = nRy;
        visited[init_x][init_y] = true;
    }
}
void Init(){
    memset(map, -1, sizeof(map));
    memset(order, 0 ,sizeof(order));
    memset(visited, false, sizeof(visited));
}
int Solve(){
    int answer = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(visited[i][j])
                answer++;
        }
    }
    return answer;
}
int main(){
    int T;
    cin >> T;
    for(int test_case=1; test_case<=T; test_case++){
        cin >> N >> W >> H;
        Init();
        
        for(int i=0; i<N; i++){
            int orc;
            cin >> orc;
            order[i] = orc;
        }
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                cin >> map[i][j];
                if(map[i][j] == 2){
                    init_x = i;
                    init_y = j;
                    visited[i][j] = true;
                }
            }
        }
        for(int i=0; i<N; i++){
            Move(order[i]);
        }
        cout << "#" << test_case << " " << Solve() << '\n';
    }
    return 0;
}