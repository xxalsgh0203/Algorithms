#include <iostream>
using namespace std;
const int MAX = 9;
int N, M;
int arr[MAX];
int visited[MAX];

void Solve(int cnt){
    if(cnt == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << '\n';
        visited[arr[M-1]] = true;
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i] && i>=arr[cnt-1]){
            arr[cnt] = i;
            Solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    Solve(0);
}