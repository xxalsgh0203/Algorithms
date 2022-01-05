#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#define INF 987654321
using namespace std;

// 지점의 개수 n, 출발지점 s, A 도착지점 a, B 도착지점 b
int solution(int n, int s, int a, int b, vector<vector<int> > fares) {
    int map[n+1][n+1];
    int answer = 0;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i == j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }

    for(int i=0; i<fares.size(); i++){
        int start = fares[i][0];
        int end = fares[i][1];
        int dist = fares[i][2];
        map[start][end] = dist;
        map[end][start] = dist;
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][k] + map[k][j] < map[i][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    answer = map[s][a] + map[s][b];

    for(int i=1; i<=n; i++){
        if(map[s][i] != INF && map[i][a] != INF && map[i][b] != INF){
            answer = min(answer, map[s][i] + map[i][a] + map[i][b]);
        }
    }

    return answer;
}

int main(){
    int n=6, s=4, a=6, b=2;
    vector<vector<int> > fares;
    cout << solution(n,s,a,b,fares);
}