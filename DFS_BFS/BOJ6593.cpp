#include <iostream>
#include <queue>
using namespace std;
int L, R, C;
int fk, fx, fy;
char building[32][32][32];
int dist[32][32][32];
int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dk[6] = {0,0,0,0,1,-1};
bool flag;
queue <pair<int, pair<int, int> > > q;

bool InRange(int k, int x, int y){
    if(k>=0 && k<L && x>=0 && x<R && y>=0 && y<C)
        return true;
    else
        return false;
}

void BFS(){
    while(!q.empty()){
        int ck = q.front().first;
        int cx = q.front().second.first;
        int cy = q.front().second.second;
        q.pop();

        for(int i=0; i<6; i++){
            int nk = ck + dk[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(!InRange(nk, nx, ny))
                continue;

            if(building[nk][nx][ny] == 'E'){
                flag = true;
            }

            if(building[nk][nx][ny] == '#')
                continue;

            if(building[nk][nx][ny] == '.' || building[nk][nx][ny] == 'E'){
                if(!dist[nk][nx][ny]){
                    dist[nk][nx][ny] = dist[ck][cx][cy] + 1;
                    q.push(make_pair(nk, make_pair(nx, ny)));
                }
            }
        }

    }
}

void Reset(){
    for(int k=0; k<L; k++){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                dist[k][i][j] = 0;
            }
        }
    }
    fk = 0;
    fy = 0;
    fx = 0;
    flag = false;
    while(!q.empty()){
        q.pop();
    }
}

int main(){
    
    while(1){
        cin >> L >> R >> C;
        if(L==0 && R==0 && C==0){
            return 0;
        }

        for(int k=0; k<L; k++){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    cin >> building[k][i][j];
                    if(building[k][i][j] == 'S'){
                        q.push(make_pair(k, make_pair(i, j)));
                    }
                    if(building[k][i][j] == 'E'){
                        fk = k;
                        fx = i;
                        fy = j;
                    }
                }
            }
        }

        BFS();

        // 디버깅
        // cout << '\n';
        // for(int k=0; k<L; k++){
        //     for(int i=0; i<R; i++){
        //         for(int j=0; j<C; j++){
        //             cout << dist[k][i][j] << " ";
        //         }
        //         cout << '\n';
        //     }
        // }

        if(flag == false){
            cout << "Trapped!" << '\n';
        }
        else{
            cout << "Escaped in " << dist[fk][fx][fy] << " minute(s)." << '\n';
        }

        Reset();
    }

    return 0;

}