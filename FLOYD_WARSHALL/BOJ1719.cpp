#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dist[201][201];
int post[201][201];
const int INF = 987654321;

void Input();
void Init();

void Input(){
    cin >> n >> m;
    Init();
    int start, end, time;
    for(int i=0; i<m; i++){
        cin >> start >> end >> time;
        dist[start][end] = time;
        dist[end][start] = time;
        post[start][end] = end;
        post[end][start] = start;
    }
}

void Init(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dist[i][j] = INF;
            if(i==j)
                dist[i][j] = 0;
        }
    }
}

void floyd_Warshall(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k]+dist[k][j]){
                   dist[i][j] = dist[i][k]+dist[k][j];
                   if(i!=k) 
                        post[i][j] = post[i][k];
                }
            }
        }
    }
}

void getAnswer(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(post[i][j] == 0)
                cout << "-" << " ";
            else
                cout << post[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    Init();
    Input();
    floyd_Warshall();
    getAnswer();
}