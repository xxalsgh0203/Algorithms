#include <algorithm>
#include <iostream>
using namespace std;

int graph[101][101];

// 플로이드 워셜 문제

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)
                graph[i][j] = 0;
            graph[i][j] = 987654321;
        }
    }

    for (int i = 0; i < M; i++) {
        int friend1, friend2;
        cin >> friend1 >> friend2;
        graph[friend1][friend2] = 1;
        graph[friend2][friend1] = 1;
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }

    int result = 987654321;
    int lowest = 0;
    for (int i = 1; i <= N; i++) {
        int bacon = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j)
                continue;
            bacon += graph[i][j];
        }
        if (result > bacon) {
            result = bacon;
            lowest = i;
        }
    }

    cout << lowest;
}