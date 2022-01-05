#include <iostream>
using namespace std;
const int MAX = 8;
int N, M;
int arr[MAX];
int visited[MAX];

void Input(){
    cin >> N >> M;
}

void Solve(int cnt){
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        visited[arr[M-1]] = true;
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            arr[cnt] = i;
            Solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    Input();
    Solve(0);
}