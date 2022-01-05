#include <iostream>
using namespace std;

int N, M;
int arr[10];
bool visited[10];

void func(int number){
    if(number == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";

        }
        cout << '\n';
        return;
    }

    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = 1;
            arr[number] = i;
            func(number+1);
            visited[i] = 0;
        }
    }

}

int main(){
    
    cin >> N >> M;
    func(0);
}