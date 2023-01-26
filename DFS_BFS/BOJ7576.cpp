#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

int graph[1000][1000];
int N, M, result = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

queue<pair<int, int>> tomato;

bool in_range(int nx, int ny)
{
    if (nx >= 0 && ny >= 0 && nx < M && ny < N)
        return true;
    else
        return false;
}

void bfs()
{
    while (!tomato.empty())
    {
        int x = tomato.front().first;
        int y = tomato.front().second;
        tomato.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (in_range(nx, ny) && graph[nx][ny] == 0)
            {
                graph[nx][ny] = graph[x][y] + 1;
                tomato.push(make_pair(nx, ny));
            }
        }
    }
}

int main()
{
    int temp_day;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &graph[i][j]); // 그래프 정보 입력
            if (graph[i][j] == 1)
                tomato.push(make_pair(i, j)); // 익은 토마토(1) -> queue(tomato)에 좌표 저장
        }
    }

    bfs();

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 0)
            {
                printf("-1\n");
                return 0;
            }
            if (result < graph[i][j])
                result = graph[i][j];
        }
    }

    printf("%d", result - 1);
    return 0;
}