#include <iostream>
using namespace std;
const int MAX = 9;
int arr[MAX];
bool visited[MAX];
int N, M;

void Input(){
    cin >> N >> M;
}

void Solve(int cnt){
    if(cnt == M + 1){
        for(int i=1; i<=M; i++){
            cout << arr[i] << " ";
        }
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i] && i>arr[cnt-1]){
            visited[i] = true;
            arr[cnt] = i;
            Solve(cnt + 1);
            visited[i] = false;
        }
    }
}

int main() {
    Input();
    Solve(1);
}