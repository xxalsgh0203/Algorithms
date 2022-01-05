#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int N, L, R;
int A[51][51];
bool visited[51][51];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void Input(){
    cin >> N >> L >> R;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }
}

bool canMove(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        int diff = abs(A[x][y] - A[nx][ny]);
        if(nx>=0 && ny>=0 && nx<N && ny<N){
            if(diff >= L && diff <= R){
                return true;
            }
        }
    }

    return false;
}

bool canMove(int x1, int y1, int x2, int y2){
    int diff = abs(A[x1][y1] - A[x2][y2]);
    if(diff >= L && diff <= R)
        return true;
    else
        return false;
}

void print(){
    cout << "**********************" << '\n';

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(visited[i][j])
                cout << "Y" << " ";
            else
                cout << "N" << " ";
        }
        cout << '\n';
    }

    cout << "*********************" << '\n';
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}

void OpenAndMove(int x, int y){
    queue <pair<int,int> > countries;
    queue <pair<int,int> > temp;
    countries.push(make_pair(x, y));
    temp.push(make_pair(x, y));
    visited[x][y] = true;
    int sum = 0;
    int cnt = 0;

    while(!countries.empty()){
        int cur_x = countries.front().first;
        int cur_y = countries.front().second;
        countries.pop();

        sum += A[cur_x][cur_y];
        cnt++;

        for(int i=0; i<4; i++){
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if(next_x<0 || next_y<0 || next_x>=N || next_y>=N)    
                continue;
            if(visited[next_x][next_y] == true)
                continue;
            if(canMove(cur_x, cur_y, next_x, next_y)){
                visited[next_x][next_y] = true;
                countries.push(make_pair(next_x,next_y));
                temp.push(make_pair(next_x,next_y));
            }
        }
    }

    int value = sum / cnt;

    while(!temp.empty()){
        int tx = temp.front().first;
        int ty = temp.front().second;
        temp.pop();
        A[tx][ty] = value;
    }
}

void Search(){
    bool check = true;
    int day = 0;

    while(check){
        // print();
        check = false; // 인구이동이 있었으면 true, 없었으면 false

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(canMove(i,j) && visited[i][j] == false){
                    OpenAndMove(i, j);
                    check = true;
                }
            }
        }

        if(check == true)
            day++;

        memset(visited, false, sizeof(visited));
    }

    cout << day;
}

void Solve(){
    Search();
}

int main(){
    Input();
    Solve();
}