#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair< pair<int,int>, pair<int, int> > > camera;
int N, M;
int office[8][8];
int copied_map[8][8];
int dx[4] = {0, 1, };
int dy[4] = {-1, 0,};
int blindspot_num = 987654321;

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> office[i][j];
            if(office[i][j] != 0 && office[i][j] != 6)
                camera.push_back(make_pair(make_pair(i,j) , make_pair(office[i][j], -1)));
        }
    }
}

void Right(int x, int y){
    for(int i=y+1; i<M; i++){
        if(copied_map[x][i] >= 1 && copied_map[x][i] <= 5)  continue;
        else if(copied_map[x][i] == 6)  break;

        copied_map[x][i] = -1;
    }
}

void Left(int x, int y){
    for(int i=y-1; i>=0; i--){
        if(copied_map[x][i] >= 1 && copied_map[x][i] <= 5)  continue;
        else if(copied_map[x][i] == 6)  break;

        copied_map[x][i] = -1;
    }
}

void Up(int x, int y){
    for(int i=x-1; i>=0; i--){
        if(copied_map[i][y] >= 1 && copied_map[i][y] <=5)   continue;
        else if(copied_map[i][y] == 6)  break;

        copied_map[i][y] = -1;
    }
}

void Down(int x, int y){
    for(int i=x+1; i<N; i++){
        if(copied_map[i][y] >= 1 && copied_map[i][y] <=5)   continue;
        else if(copied_map[i][y] == 6)  break;

        copied_map[i][y] = -1;
    }
}

void copyMap(){
    int copied_arr[8][8];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            copied_map[i][j] = office[i][j];
        }
    }
}

void Check(){
    copyMap();
    for(int i=0; i<camera.size(); i++){
        if(camera[i].second.first == 1){
            if(camera[i].second.second == 0)    Right(camera[i].first.first, camera[i].first.second);
            else if(camera[i].second.second == 1)   Down(camera[i].first.first, camera[i].first.second);
            else if(camera[i].second.second == 2)   Left(camera[i].first.first, camera[i].first.second);
            else if(camera[i].second.second == 3)   Up(camera[i].first.first, camera[i].first.second);
        }
        else if(camera[i].second.first == 2){
            if(camera[i].second.second == 0 || camera[i].second.second == 1){
                Left(camera[i].first.first, camera[i].first.second);
                Right(camera[i].first.first, camera[i].first.second);
            }
            else if(camera[i].second.second == 2 || camera[i].second.second == 3){
                Up(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
            }
        }
        else if(camera[i].second.first == 3){
            if(camera[i].second.second == 0){
                Up(camera[i].first.first, camera[i].first.second);
                Right(camera[i].first.first, camera[i].first.second);
            }    
            else if(camera[i].second.second == 1){
                Right(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
            }
            else if(camera[i].second.second == 2){
                Down(camera[i].first.first, camera[i].first.second);
                Left(camera[i].first.first, camera[i].first.second);
            }
            else if(camera[i].second.second == 3){
                Left(camera[i].first.first, camera[i].first.second);
                Up(camera[i].first.first, camera[i].first.second);
            }   
        }
        else if(camera[i].second.first == 4){
            if(camera[i].second.second == 0){
                Left(camera[i].first.first, camera[i].first.second);
                Up(camera[i].first.first, camera[i].first.second);
                Right(camera[i].first.first, camera[i].first.second);
            }    
            else if(camera[i].second.second == 1){
                Up(camera[i].first.first, camera[i].first.second);
                Right(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
            }
            else if(camera[i].second.second == 2){
                Right(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
                Left(camera[i].first.first, camera[i].first.second);
            }
            else if(camera[i].second.second == 3){
                Left(camera[i].first.first, camera[i].first.second);
                Up(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
            } 
        }
        else if(camera[i].second.first == 5){
                Left(camera[i].first.first, camera[i].first.second);
                Up(camera[i].first.first, camera[i].first.second);
                Right(camera[i].first.first, camera[i].first.second);
                Down(camera[i].first.first, camera[i].first.second);
        }
    }
}

int calBlindSpot(){
    int result = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(copied_map[i][j] == 0){
                result++;
            }
        }
    }
    return result;
}

void setDirection(int cnt){
    if(cnt == camera.size()){
        Check();
        blindspot_num = min(blindspot_num, calBlindSpot());
        return;
    }

    for(int i=0; i<4; i++){
        camera[cnt].second.second = i;
        setDirection(cnt + 1);
    }
}

void Solve(){
    setDirection(0);
    cout << blindspot_num;
}

int main(){
    Input();
    Solve();
}