#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 사용
using namespace std;

int graph[50][50];
bool visited[50][50] = {0};
int T, M, N; // 테스트 케이스 개수 T, 배추밭 가로길이 M, 세로길이 N
vector<int> result;

bool dfs(int x, int y){
    if(x<0 || y<0 || x>=M || y>=N)
        return false;
    if(graph[x][y] == 1 && visited[x][y] != 1){  // 배추가 있고 방문하지 않은 곳이면
        visited[x][y] = 1; // 방문처리 후
        dfs(x-1, y);
        dfs(x+1, y);
        dfs(x, y-1);
        dfs(x, y+1);
        return true;
    }
    return false;
}

int main(){
    int K; // 배추 위치의 개수 K
    int x, y, i, j;

    scanf("%d\n", &T);

    for(int c=0; c<T; c++){
        int count = 0;
        memset(graph, 0, sizeof(graph)); // 초기화
        memset(visited, 0, sizeof(visited)); // 초기화

        cin >> M >> N >> K;
        
        for(i=0; i<K; i++){
            cin >> x >> y;
            graph[x][y] = 1;
        }

        for(i=0; i<M; i++){
            for(j=0; j<N; j++){
                if(dfs(i,j))
                    count++;
            }
        }
        result.push_back(count);
    }

    for(i=0; i<result.size(); i++){
        cout << result[i] << endl;
    }

}