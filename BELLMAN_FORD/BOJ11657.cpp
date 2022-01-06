#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int N, M;
int A, B, C;
int graph[501][501];

void Input(){
    cin >> N >> M;

    for(int i=0; i<500; i++){
        for(int j=0; j<500; j++){
            graph[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++){
        cin >> A >> B >> C;
        graph[A][B] = min(graph[A][B], C);
    }
}

void Solution(){
    
}

void Solve(){
    Input();
    Solution();
}

int main(){
    Solve();

    return 0;
}