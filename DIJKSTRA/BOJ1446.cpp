#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, D;
int dist[10001];
struct info{
    int dest;
    int cost;
};
info tmp;
vector <info> v[10001];
void Input(){
    cin >> N >> D;
    for(int i=0; i<N; i++){
        int val, start, end;
        cin >> start >> end >> val;
        if(end-start < val)
            continue;
        if(end > D)
            continue;
        tmp.dest = end;
        tmp.cost = val;
        v[start].push_back(tmp);
    }
}

void Init(){
    for(int i=0; i<=D; i++){
        dist[i] = i;
    }
}

void Solve(){
    for(int i=0; i<=D; i++){
        if(i>=1)
            dist[i] = min(dist[i], dist[i-1] + 1);
        for(int j=0; j<v[i].size(); j++){
            int destination = v[i][j].dest;
            int shortcutdist = v[i][j].cost;
            if(dist[i] + shortcutdist < dist[destination]){
                dist[destination] = dist[i] + shortcutdist;
            }
        }
    }
}

int main(){
    Input();
    Init();
    Solve();
    cout << dist[D];
}