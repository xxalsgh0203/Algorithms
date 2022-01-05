#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321
int n, m;
int a, b, c;
int map[102][102];

void Init(){
    for(int i=0; i<102; i++){
        for(int j=0; j<102; j++){
            map[i][j] = INF;
        }
    }
}

void Input(){
    cin >> n;
    cin >> m;

    Init();

    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);
    }
}

void FloydWarshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][k]!= INF && map[k][j] != INF){
                    if(map[i][j] > map[i][k] + map[k][j]){
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j] == INF || i==j)
                cout << 0 << " ";
            else
                cout << map[i][j] << " ";
        }
        cout << '\n';
    }
}

void Solve(){
    Input();
    FloydWarshall();
}

int main(){
    Solve();

    return 0;
}