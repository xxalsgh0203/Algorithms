#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int map[101][101];
int items[101];
int n, m, r;

void Init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
        }
    }
}

void Input(){
    cin >> n >> m >> r;

    Init();

    for(int i=1; i<=n; i++)
        cin >> items[i];

    for(int i=0; i<r; i++){
        int a, b, dest;
        cin >> a >> b >> dest;
        map[a][b] = dest;
        map[b][a] = dest;
        
    }     
}

void floyd_warshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
}

void Solve(){
    int sum = 0, result = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(map[i][j] <= m){
                sum += items[j];
            }
        }
        result = max(result , sum);
        sum = 0;
    }

    cout << result;
}

int main(){
    Input();
    floyd_warshall();
    Solve();
}