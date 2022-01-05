#include <iostream>
#include <queue>
using namespace std;

const int INF = 987654321;
int city[1001][1001];
int cost[1001][1001];
int nx[4] = {0,1,0,-1};
int ny[4] = {-1,0,1,0};
int n,m;
void Input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> city[i][j];
            cost[i][j] = INF;
        }
    }
}
bool inRange(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}

void Dijkstra(){
    priority_queue <pair<int,pair<int, int> > > pq;
    pq.push(make_pair(-city[0][0], make_pair(0,0)));
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int dist = -pq.top().first;
        pq.pop();

        if(cost[x][y] <= dist)  
            continue;
        cost[x][y] = dist;
        if(x == n-1 && y == m-1)
            break;
        
        for(int i=0; i<4; i++){
            int dx = x + nx[i];
            int dy = y + ny[i];
            if(inRange(dx, dy)){
                if(city[dx][dy] == 0){ // 도로가 이미 존재
                    pq.push(make_pair(-dist,make_pair(dx,dy)));
                }
                if(city[dx][dy] == 1){ // 도로가 없고 1의 비용으로 도로를 건설할 수 있는 단위격자
                    pq.push(make_pair(-(dist+1),make_pair(dx,dy)));
                }
                if(city[dx][dy] == 2){ // 도로가 없고 2의 비용으로 도로를 건설할 수 있는 단위 격자
                    pq.push(make_pair(-(dist+2),make_pair(dx,dy)));
                }
            }
        }
    }
}

int Solve(){
    if(city[0][0] == -1 || city[n-1][m-1] == -1){
        return -1;
    }
    if(cost[n-1][m-1] == INF){
        return -1;
    }
    return cost[n-1][m-1];
}

    
int main(){
    Input();
    Dijkstra();
    cout << Solve();
}