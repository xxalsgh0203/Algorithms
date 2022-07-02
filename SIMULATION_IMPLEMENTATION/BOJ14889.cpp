#include <iostream>
#include <cmath>
using namespace std;

int arr[20][20];
bool visited[20];
int N;
int result = 987654321;

void combi(int cnt, int current){
    if(cnt == N/2){ // 팀원 배정이 끝났을때
        int start_team = 0;
        int link_team = 0;

        // check
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(visited[i] && visited[j]){
                    start_team += arr[i][j];
                    start_team += arr[j][i];
                }else if(!visited[i] && !visited[j]){
                    link_team += arr[i][j];
                    link_team += arr[j][i];
                }
            }
        }

        result = min(result, abs(start_team - link_team));
    }

    // 팀원 배정이 아직 안되었다면
    for(int i=0; i<N; i++){
        if(!visited[i] && i>current){
            visited[i] = true;
            combi(cnt+1, i);
            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    combi(0, -1);

    cout << result << '\n';
}