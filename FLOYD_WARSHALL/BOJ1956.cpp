#include <iostream>
#include <algorithm>
#define INF 4000000
using namespace std;

int V, E;
int a, b, c;
int map[400][400];

void Init(){
    for(int i=0; i<400; i++){
        for(int j=0; j<400; j++){
            map[i][j] = INF;
        }
    }
}

void Input(){
    cin >> V >> E;

    Init();

    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        map[a-1][b-1] = c;
    }
}

void Solution(){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }

    int temp = INF;

    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(i == j)
                continue;
            if(map[i][j] != INF && map[j][i] != INF){
                temp = min(temp, map[i][j] + map[j][i]);
            }
        }
    }

    if(temp == INF){
        cout << -1;
    }
    else{
        cout << temp;
    }
}

void Solve(){
    Input();
    Solution();
}

int main(){
    Solve();
}