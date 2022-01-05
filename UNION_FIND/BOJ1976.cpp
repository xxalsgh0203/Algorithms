#include <iostream>
using namespace std;
int N, M;
int parent[201];
int travel[1001];

int findParent(int child){
    if(parent[child] == child)
        return child;
    return parent[child] = findParent(parent[child]);
}

void UnionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a<b)
        parent[b] = a;
    else
        parent[a] = b;
}

void Init(int N){
    for(int i=1; i<=N; i++){
        parent[i] = i;
    }
}

void Input(){
    bool connected;
    cin >> N >> M;
    Init(N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> connected;
            if(connected)
                UnionParent(i,j);
        }
    }
}

void Solve(){
    for(int i=1; i<=M; i++){
        cin >> travel[i];
    }
    int temp = findParent(travel[1]);
    for(int i=2; i<=M; i++){
        if(findParent(travel[i]) == temp)
            continue;
        else{
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(){
    Input();
    Solve();
}